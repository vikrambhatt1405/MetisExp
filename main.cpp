#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <functional>
#include <random>
#include <parmetis.h>
#include <mpi.h>

void adjtocsr(int** xadj,
              int** adjncy,
              int** vtxdist,
              int* nvtxs,
              int* nedges,
              const char* file_path,
              MPI_Comm* comm);

int main(int argc, char* argv[]) {
    MPI_Comm comm = MPI_COMM_WORLD;
    int pid, nprocs;
    MPI_Init(&argc, &argv);
    idx_t* adjncy;
    idx_t* xadj;
    idx_t* vtxdist;
    idx_t* adjwgt;
    idx_t nvtxs;
    idx_t nedges;
    idx_t wgtflag=0, numflag =0 , ncon = 1, nparts = 2;
    idx_t options[] = {0};
    idx_t edgecut=0;
    idx_t* part;
    auto tpwgts = new real_t[ncon*nparts];
    for(int i=0; i<ncon*nparts; ++i){
        tpwgts[i] = 1/((float_t )nparts);
    }
    auto ubvec = new real_t[ncon];
    for(int i=0; i<ncon; ++i){
        ubvec[i] = 2.00;
    }
    //const std::string file_path(argv[1]);
    adjtocsr(&xadj, &adjncy, &vtxdist, &nvtxs, &nedges, argv[1], &comm);
    MPI_Comm_rank(comm, &pid);
    std::cout<<"Processor: "<<pid<<std::endl;
    std::cout<<"Vertices: "<<nvtxs<<std::endl;
    //std::cout<<"Edges: "<<nedges<<std::endl;
    //std::cout<<std::endl;
    MPI_Barrier(comm);
    //std::random_device r;
    //std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
    //std::mt19937       eng(seed); // a source of random data
    //std::uniform_int_distribution<int> dist(1,10);
    //std::vector<int> v(nedges);
    //generate(v.begin(), v.end(), bind(dist, eng));
    //adjwgt = new int[nedges];
    //std::copy(v.begin(), v.end(), adjwgt);
    //for (int i=0; i<nedges; ++i){
      //adjwgt[i] = 1;
    //}
    MPI_Comm_size(comm, &nprocs);
    part = new idx_t[nedges];
    double start_time = -MPI_Wtime();
    int rval = ParMETIS_V3_PartKway(vtxdist, xadj, adjncy, NULL, NULL, &wgtflag, &numflag, &ncon, &nparts, tpwgts, ubvec,
                                options, &edgecut, part, &comm);
    double elapsed_time, max_time=0;
    std::cout<<"done"<<std::endl;
    if(rval==METIS_OK){
	elapsed_time = start_time+MPI_Wtime();
    }else{
	MPI_Abort(comm, 1);
    }
    MPI_Reduce(&elapsed_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, comm);
    if(pid==0){
	std::cout<<nprocs<<" "<<max_time<<std::endl;
	}
    MPI_Finalize();
    return 0;
}
