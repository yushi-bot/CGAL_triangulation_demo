
#include <iostream>
#include <string>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_vertex_base_with_info_3.h>
#include <CGAL/Triangulation_cell_base_with_info_3.h>
#include <CGAL/Delaunay_triangulation_3.h>

// kernel
typedef CGAL::Exact_predicates_inexact_constructions_kernel
    K;

// Vertex base
typedef CGAL::Triangulation_vertex_base_3<K>
    Vb;
typedef CGAL::Triangulation_vertex_base_with_info_3<int, K, Vb>
    VbI;

// Cell base
typedef CGAL::Triangulation_cell_base_3<K>
    Cb;

typedef CGAL::Triangulation_cell_base_with_info_3<int, K, Cb>
    CbI;

//data structure
typedef CGAL::Triangulation_data_structure_3<VbI, CbI>
    cdTds;

typedef CGAL::Delaunay_triangulation_3<K, cdTds>
    CDT;

typedef CDT::Point_3
    Point;

int main()
{
    // construction from a list of points :
    std::vector<std::pair<Point, int>> pointsList;
    // make pair with index
    pointsList.push_back(std::make_pair(Point(0, 0, 0), 0));
    pointsList.push_back(std::make_pair(Point(1, 0, 0), 1));
    pointsList.push_back(std::make_pair(Point(0, 1, 0), 2));

    pointsList.push_back(std::make_pair(Point(0, 0, 1), 3));
    pointsList.push_back(std::make_pair(Point(1, 0, 1), 4));
    pointsList.push_back(std::make_pair(Point(1, 1, 1), 5));

    char vertexSymbol[]  = {'A','B','C','D','E','F'};

    CDT cdt;
    cdt.insert(pointsList.begin(), pointsList.end());
    assert(cdt.is_valid());
    std::cout << "There is " << cdt.finite_vertex_handles().size() << " points in the list;" << std::endl;
    std::cout << "They are :" << std::endl;
    // iterate all vertex
    for (CDT::Vertex_handle v : cdt.finite_vertex_handles())
    {
        std::cout << vertexSymbol[v->info()]
                  << ": (" << v->point().x()
                  << ", " << v->point().y()
                  << ", " << v->point().z()
                  << ")"
                  << std::endl;
    }

    int cellIndex = 0;
    int cellCount = cdt.finite_cell_handles().size();
    std::cout<<"\n\n"<<std::endl;

    std::cout << "There is " << cellCount << " cells in the list;" << std::endl;
    std::cout << "They are :" << std::endl;
    // iterate all cells
    for (CDT::Cell_handle c : cdt.finite_cell_handles())
    {
        std::cout<<"Cell" << cellIndex
                <<": ";

        for(int i = 0; i < 4; i++){
            CDT::Vertex_handle v = c->vertex(i);
            std::cout << vertexSymbol[v->info()];
        }
        std::cout<<std::endl;
        cellIndex++;
    }

    return 0;
}