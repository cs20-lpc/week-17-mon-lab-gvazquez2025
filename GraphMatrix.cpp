#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) {
    v = numV;
    e = 0;
    graphType = type;

    adjMatrix = new bool*[v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new bool[v];
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    if (i < 0 || i >= v || j < 0 || j >= v) {
        throw string("isEdge: invalid vertex index");
    }
    return adjMatrix[i][j];
}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    if (i < 0 || i >= v || j < 0 || j >= v) {
        throw string("toggleEdge: invalid vertex index");
    }

    if (adjMatrix[i][j]) {
        adjMatrix[i][j] = false;
        if (graphType == UNDIRECTED) {
            adjMatrix[j][i] = false;
        }
        e--;
    }
    else {
        adjMatrix[i][j] = true;
        if (graphType == UNDIRECTED) {
            adjMatrix[j][i] = true;
        }
        e++;
    }
}
