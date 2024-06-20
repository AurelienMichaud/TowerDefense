#pragma once

#include <img/img.hpp>
#include <vector>

// type de Case
enum class typeCase
{
    chemin,

    chemin_vertical,
    chemin_horizontal,

    chemin_haut_gauche,
    chemin_haut_droite,
    chemin_gauche_bas,
    chemin_droite_bas,

    chemin_T,
    chemin_T_inverse,
    chemin_T_gauche,

    chemin_depart,
    chemin_arrivee,

    nonchemin,

    nonchemin_1,
    nonchemin_2,
    nonchemin_3,

    emplacement_tour,
};

struct Case
{
    // Position début de case
    int posx{};
    int posy{};
    // Position fin de case
    int posx_plus20{};
    int posy_plus20{};

    // Couleur
    int R{};
    int G{};
    int B{};

    typeCase typeDeCase{};

    int g; // cost from start to this cell
    int h; // heuristic cost from this cell to end
    int f; // total cost (g + h)

    Case* parent;

    Case() {}
    Case(int r, int g, int b) : R(r), G(g), B(b), g(std::numeric_limits<int>::max()), h(std::numeric_limits<int>::max()), f(std::numeric_limits<int>::max()), parent(nullptr) {}

    

};

int heuristic(int x1, int y1, int x2, int y2);

// Custom comparator for priority queue
struct CompareF {
    bool operator()(Case* a, Case* b) {
        return a->f > b->f;
    }
};

struct Node
{

};

std::vector<Case> ChargeVectMap(img::Image *image);
std::vector<std::vector<Case>> ChargeMatMap(img::Image *image);
std::vector<Case> VerifPlacementTourVectMap(img::Image* image);
void displayMap(const std::vector<std::vector<Case>>& map2d);
