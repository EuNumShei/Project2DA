#ifndef PROJECT1DATASETSMALL_REDE_H
#define PROJECT1DATASETSMALL_REDE_H
#include "Graph.h"
#include <string>
#include <unordered_map>

using namespace std;

class Rede {
public:
    Rede(int num, bool r_g){
        ler_ficheiro_navios();
        ler_ficheiro_estadios();
        ler_ficheiro_turismo();
        ler_ficheiro_graph(num, r_g);
        /*g.addVertex("R_0");
        g.addVertex("PS_0");
        for(auto vertex : g.getVertexSet()){
            if(vertex->getInfo()[0] == 'R'){
                g.addEdge("R_0", vertex->getInfo(), reservoirs.at(vertex->getInfo()).get_max_delivery());
            }
            if(vertex->getInfo()[0] == 'C'){
                g.addEdge(vertex->getInfo(), "PS_0", cities.at(vertex->getInfo()).get_demand());
            }
        }*/
    }
    void ler_ficheiro_navios();
    void ler_ficheiro_graph(int num, bool r_g);
    void ler_ficheiro_estadios();
    void ler_ficheiro_turismo();
    bool verificar_edge(const int& source, const int& dest);
    void print_edges_stadiums();
    void print_edges_tourism();
    void print_edges_shipping();
    void print_edges_graph();
    void edmonds_karp();
    void testAndVisit(std::queue< Vertex<string>*> &q, Edge<string> *e, Vertex<string> *w, double residual);
    bool findAugmentingPath(Vertex<string> *s, Vertex<string> *t);
    void augmentFlowAlongPath(Vertex<string> *s, Vertex<string> *t, double f);
    double findMinResidualAlongPath(Vertex<string> *s, Vertex<string> *t);
    void initialize_flow();
    double max_flow(const string& cidade);
    void max_flow();
    void escrever_ficheiro_2_2();
    void escrever_ficheiro_3_1();
    void dados_2_2();
    void dados_3_1();
    bool remover_reservatorio(string reservoir);
    void dados_3_2();
    void escrever_ficheiro_3_2();
    bool remover_station(string station);
    void remover_pipes();
    void dados_3_3();
private:
    Graph<int> g;
    Graph<int> shipping;
    Graph<int> stadiums;
    Graph<int> tourism;
    vector<Edge<int> *> edges;
};


#endif //PROJECT1DATASETSMALL_REDE_H
