#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <mpi.h>

void adjtocsr(int** xadj,
              int** adjncy,
              int** vtxdist,
              int* nvtxs,
              int* nedges,
              const char* file_path,
              MPI_Comm *comm){
    int id;
    int n_proc;
    int adjncy_size, xadj_size;
    int total_vtxs, total_edges;
    std::vector<int> _xadj = {0};
    std::vector<int> _adjncy;
    MPI_Comm_rank(*comm, &id);
    MPI_Comm_size(*comm, &n_proc);
    if(id ==  n_proc-1) {
        std::ifstream adj_file;
        adj_file.open(file_path, std::ios::in);
        if (!adj_file) {
            std::cout << "FILE NOT FOUND:"<<file_path<<std::endl;
            MPI_Abort(*comm, 1);
        }//else{
	  //std::cout<<"File opened Successfully"<<std::endl;
         //}
        std::string s;
        while(getline(adj_file, s)){
            if(s.rfind("%")!=0) break;
        }
        //getline(adj_file, s);
        auto start = 0U;
        std::string delim = " ";
        auto end = s.find(delim);
        std::vector<std::string> graph_pms;
        while (end != std::string::npos) {
            //std::cout<<s.substr(start, end-start)<<std::endl;
            graph_pms.push_back(s.substr(start, end-start));
            start = end + delim.length();
            end = s.find(delim, start);
        }
        graph_pms.push_back(s.substr(start, end-start));
        //std::cout<< graph_pms[0] <<" "<<graph_pms[1]<<std::endl;
        total_vtxs = std::stoi(graph_pms[0]);
        total_edges = std::stoi(graph_pms[1]);
        MPI_Bcast(&total_vtxs, 1, MPI_INT, n_proc - 1, *comm);
        MPI_Bcast(&total_edges, 1, MPI_INT, n_proc - 1, *comm);
        for (int process = 0; process < n_proc - 1; ++process) {
            int vtxs_read=0;
            _xadj = {0};
                while(vtxs_read<total_vtxs/n_proc){
                    getline(adj_file, s);
                    std::string delim = " ";
                    auto start = 0U;
                    auto end = s.find(delim);
                    if(!s.empty()) {
                        while (end != std::string::npos) {
                            _adjncy.push_back(std::stoi(s.substr(start, end - start)) - 1);
                            start = end + delim.length();
                            end = s.find(delim, start);
                        }
                   // _adjncy.push_back(std::stoi(s.substr(start, end-start))-1);
                    std::cout<<s.substr(start, end-start)<<std::endl;

                    }
                    vtxs_read+=1;
                    _xadj.push_back(_adjncy.size());
                }
                adjncy_size = _adjncy.size();
                xadj_size = _xadj.size();
                MPI_Send(&adjncy_size, 1, MPI_INT, process, process+8, *comm);
                MPI_Send(&xadj_size, 1, MPI_INT, process, process+16, *comm);
                MPI_Send(_adjncy.data(), _adjncy.size(), MPI_INT, process, process+32, *comm);
                MPI_Send(_xadj.data(), _xadj.size(), MPI_INT, process, process+64, *comm);
                _xadj.clear();
                _adjncy.clear();
        } // Data distributed for all other process at this point
        // Now assign the rest of data to this process n_proc-1
        _xadj = {0};
        _adjncy.clear();
        while (getline(adj_file, s)){
                std::string delim = " ";
                auto start = 0U;
                auto end = s.find(delim);
                if (!s.empty()){
                while (end != std::string::npos)
                {
                    _adjncy.push_back(std::stoi(s.substr(start, end-start))-1);
                    start = end + delim.length();
                    end = s.find(delim, start);
                    }
                 _adjncy.push_back(std::stoi(s.substr(start, end-start))-1);
                }
                _xadj.push_back(_adjncy.size());
            }
	
        *nvtxs = _xadj.size()-1;
        *nedges = _adjncy.size();
        *xadj = new int[_xadj.size()];
        *adjncy = new int[_adjncy.size()];
        std::copy(_xadj.begin(), _xadj.end(), *xadj);
        std::copy(_adjncy.begin(), _adjncy.end(), *adjncy);
        adj_file.close();
    }else{
        MPI_Status status[4];
        MPI_Request request[4];
        MPI_Bcast(&total_vtxs, 1, MPI_INT, n_proc-1, *comm);
        MPI_Bcast(&total_edges, 1, MPI_INT, n_proc - 1, *comm);
        MPI_Recv(&adjncy_size, 1, MPI_INT, n_proc-1, id+8, *comm, &status[0]);
        MPI_Recv(&xadj_size, 1, MPI_INT, n_proc-1, id+16, *comm, &status[1]);
        *nvtxs = xadj_size-1;
        *nedges = adjncy_size;
        *adjncy = new int[adjncy_size];
        *xadj = new int[xadj_size];
        MPI_Recv(*adjncy, adjncy_size, MPI_INT, n_proc-1, id+32, *comm, &status[2]);
        MPI_Recv(*xadj, xadj_size, MPI_INT, n_proc-1, id+64, *comm, &status[3]);
    }
    //Define vtxdist for all processes
    *vtxdist = new int[n_proc+1]();
    for(int i=1; i<n_proc; ++i) {
        (*vtxdist)[i] = i*(total_vtxs/n_proc);
    }
    (*vtxdist)[n_proc] =  total_vtxs;
}
