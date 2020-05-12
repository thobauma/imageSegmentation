#include <iostream>
#include <iomanip> // for setprecision

#include "bitmap.hpp"
#include "graph.hpp"
#define DEBUG

void ShowResult(const Bitmap& original, Graph& graph, const std::string& filename){
    Bitmap resbmp = graph.graphToBitmap();
    // std::stringstream s;
    // s << filename << ".bmp";
    std::string originalF = "./images/"+filename+"Original.bmp";
    original.Save(originalF);
    #ifdef DEBUG
        std::cout << "original saved" << std::endl;
    #endif
    std::string resultF = "./images/"+filename+"Seg.bmp";
    resbmp.Save(resultF);
    #ifdef DEBUG
        std::cout << "segmented image saved" << std::endl;
    #endif

}

Graph testGraph()
{
    Graph g(6, 0, 5);
    g.addEdge(0, 1,16);
    g.addEdge(0, 2,13);
    g.addEdge(1, 2,10);
    g.addEdge(1, 3,12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4,14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5,20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);
    g.printTest();
    auto mf = g.edmondsKarp();
    std::cout << "max flow: " << mf << std::endl;
    g.printTest();
    return g;
}

int main(){
    Graph a = testGraph();
    // std::cout << std::setprecision(3); // don't remove
    // // std::cout << "image name (e.g. bird, peppers or sailboat)?";
    // std::cout << "image name (e.g. test1, test2, test3)?" << std::endl;
    // std::string filename;
    // #ifdef DEBUG
    //     filename = "debug";
    // #else
    //     std::cin >> filename;
    // #endif
    // Bitmap bitmap = readpgm("./images/" + filename + ".pgm");
    // #ifdef DEBUG
    //     std::cout << std::endl << "bitmap initalized" << std::endl;
    // #endif
    // Graph g(bitmap);
    // #ifdef DEBUG
    //     std::cout << "graph initialized" << std::endl;
    // #endif
    // g.minCut();
    // g.printInfo();
    // #ifdef DEBUG
    //     std::cout << "minCut done" << std::endl;
    // #endif
    // ShowResult(bitmap, g, filename);

    return 0;
}
