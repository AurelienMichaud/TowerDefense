#include "Map.hpp"
#include <vector>
#include <iostream>

std::vector<Case> ChargeVectMap(img::Image* image) {
    std::vector<Case> VectCaseMap{};

    const uint8_t* data { image->data() };
    const unsigned int width { image->width() };
    const unsigned int height { image->height() };

    for(unsigned int i{0}; i<10; i++) {
        for(unsigned int j{0}; j<10; j++) {
            uint8_t r = data[(i+width*j)*3+0];
            uint8_t g = data[(i+width*j)*3+1];
            uint8_t b = data[(i+width*j)*3+2];
            Case C(r,g,b);

            if(r == 0 && g == 0 && b == 0) {
                    C.typeDeCase = typeCase::nonchemin;
            }
            if(r == 0 && g != 0 && b == 0) {
                C.typeDeCase = typeCase::emplacement_tour;
            }
            if(r != 0 && g != 0 && b != 0) {
                C.typeDeCase = typeCase::chemin;
            }
            if(r != 0 && g == 0 && b == 0) {
                C.typeDeCase = typeCase::chemin_depart;
            }
            if(r == 0 && g == 0 && b != 0) {
                C.typeDeCase = typeCase::chemin_arrivee;
            }

            VectCaseMap.push_back(C);
        
        }
    }

    return VectCaseMap;
}

std::vector<Case> VerifPlacementTourVectMap(img::Image* image) {
    std::vector<Case> VectPixelMap{};

    const uint8_t* data { image->data() };
    const unsigned int width { image->width() };
    const unsigned int height { image->height() };

    for(unsigned int i{0}; i<width; i++) {
        for(unsigned int j{0}; j<height; j++) {
            uint8_t r = data[(i+width*j)*3+0];
            uint8_t g = data[(i+width*j)*3+1];
            uint8_t b = data[(i+width*j)*3+2];
            Case P(r,g,b);
            VectPixelMap.push_back(P);
        }
    }

    return VectPixelMap;
}

std::vector<std::vector<Case>> ChargeMatMap(img::Image* image) {
    std::vector<std::vector<Case>> MatCaseMap(image->height(), std::vector<Case>(image->width()));

    const uint8_t* data { image->data() };

    for(unsigned int i{0}; i<image->height(); i++) {
        for(unsigned int j{0}; j<image->width(); j++) {
            uint8_t r = data[(i+image->width()*j)*3+0];
            uint8_t g = data[(i+image->width()*j)*3+1];
            uint8_t b = data[(i+image->width()*j)*3+2];

            Case C(r,g,b);

            C.posx = j*20;
            C.posy = i*20;
            C.posx_plus20 = (j+1)*20;
            C.posy_plus20 = (i+1)*20;

            if(r == 0 && g == 0 && b == 0) {
                C.typeDeCase = typeCase::nonchemin;
            }
            else if(r == 0 && g != 0 && b == 0) {
                C.typeDeCase = typeCase::emplacement_tour;
            }
            else if(r != 0 && g != 0 && b != 0) {
                C.typeDeCase = typeCase::chemin;
            }
            else if(r == 0 && g == 0 && b != 0) {
                C.typeDeCase = typeCase::chemin_depart;
            }
            else if(r != 0 && g == 0 && b == 0) {
                C.typeDeCase = typeCase::chemin_arrivee;
            }

            MatCaseMap.at(j).at(i) = C;
        }
    }
        std::cout << MatCaseMap.at(7).at(5).posx << std::endl;


    return MatCaseMap;
    
}

// Heuristic function (Manhattan distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}


void displayMap(const std::vector<std::vector<Case>>& map2d) {
    for (int y = 0; y < (int) map2d.size(); ++y) {
        for (int x = 0; x < (int) map2d[y].size(); ++x) {
            switch (map2d[y][x].typeDeCase) {
                case typeCase::nonchemin:
                    std::cout << "# ";
                    break;
                case typeCase::emplacement_tour:
                    std::cout << "T ";
                    break;
                case typeCase::chemin:
                    std::cout << ". ";
                    break;
                case typeCase::chemin_depart:
                    std::cout << "S ";
                    break;
                case typeCase::chemin_arrivee:
                    std::cout << "E ";
                    break;
            }
        }
        std::cout << "///"<<std::endl;
    }

    
}



