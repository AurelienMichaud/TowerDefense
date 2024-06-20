#include "App.hpp"
#include <queue>
#include <unordered_set>
#include <random>

App::App() : _previousTime(0.0), _viewSize(2.0) {
    // img::Image test {img::load(make_absolute_path("images/map_design2_v1.png", true), 3, true)};
    // _texture = loadTexture(test);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Chargement des textures de la Map
    tiles_textures[typeCase::chemin_vertical] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_vertical.png", true), 3, true));
    tiles_textures[typeCase::chemin_horizontal] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_horizontal.png", true), 3, true));

    tiles_textures[typeCase::chemin_haut_gauche] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_tournant_haut_gauche.png", true), 3, true));
    tiles_textures[typeCase::chemin_haut_droite] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_tournant_haut_droite.png", true), 3, true));
    tiles_textures[typeCase::chemin_gauche_bas] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_tournant_gauche_bas.png", true), 3, true));
    tiles_textures[typeCase::chemin_droite_bas] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_tournant_droite_bas.png", true), 3, true));

    tiles_textures[typeCase::chemin_T] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_T.png", true), 3, true));
    tiles_textures[typeCase::chemin_T_inverse] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_T_inverse.png", true), 3, true));
    tiles_textures[typeCase::chemin_T_gauche] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_T_gauche.png", true), 3, true));

    tiles_textures[typeCase::chemin_depart] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_depart.png", true), 3, true));
    tiles_textures[typeCase::chemin_arrivee] = loadTexture(img::load(make_absolute_path("images/Tuiles/chemin_arrivee.png", true), 3, true));

    tiles_textures[typeCase::emplacement_tour] = loadTexture(img::load(make_absolute_path("images/Tuiles/emplacement_tour.png", true), 3, true));

    tiles_textures[typeCase::nonchemin_1] = loadTexture(img::load(make_absolute_path("images/Tuiles/nonchemin_1.png", true), 3, true));
    tiles_textures[typeCase::nonchemin_2] = loadTexture(img::load(make_absolute_path("images/Tuiles/nonchemin_2.png", true), 3, true));
    tiles_textures[typeCase::nonchemin_3] = loadTexture(img::load(make_absolute_path("images/Tuiles/nonchemin_3.png", true), 3, true));

    // Chargement des textures des ennemis
    ennemis_textures[typeEnnemi::elisabeth] = loadTexture(img::load(make_absolute_path("images/Ennemis/elisabeth.png", true), 3, true));
    ennemis_textures[typeEnnemi::colin] = loadTexture(img::load(make_absolute_path("images/Ennemis/colin.png", true), 3, true));
    ennemis_textures[typeEnnemi::milan] = loadTexture(img::load(make_absolute_path("images/Ennemis/milan.png", true), 3, true));

    // Chargement des textures des tours
    tours_textures[typeTour::archer] = loadTexture(img::load(make_absolute_path("images/Tours/TourArcher.png", true), 3, true));
    tours_textures[typeTour::chevalier] = loadTexture(img::load(make_absolute_path("images/Tours/TourChevalier.png", true), 3, true));
    tours_textures[typeTour::sorcier] = loadTexture(img::load(make_absolute_path("images/Tours/TourSorcier.png", true), 3, true));

    this->map2d = ChargeMatMap(&map10x10);
    displayMap(this->map2d);

    
    std::cout << "AHAHAHAH";

    this->preCalculation();
    this->populate();

}



void App::setup() {
    // Set the clear color to a nice blue
    glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

    // Setup the text renderer with blending enabled and white text color
    TextRenderer.ResetFont();
    TextRenderer.SetColor(SimpleText::TEXT_COLOR, SimpleText::Color::WHITE);
    TextRenderer.SetColorf(SimpleText::BACKGROUND_COLOR, 0.f, 0.f, 0.f, 0.f);
    TextRenderer.EnableBlending(true);

    // float randPosx, randPosy;
    // randPosx;
}

// void App::update() {

//     const double currentTime { glfwGetTime() };
//     const double elapsedTime { currentTime - _previousTime};
//     _previousTime = currentTime;

//     _angle += 10.0f * elapsedTime;
//     // _angle = std::fmod(_angle, 360.0f);
    
//     render();
// }

void App::render() {
    if(JeuStart==1) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Clear the color and depth buffers of the frame buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // déplacement du repère en haut à gauche
        glTranslatef(-1.f, 1.f, 0.f);

        std::vector<Case> VectCaseMap{};
        VectCaseMap = ChargeVectMap(&map10x10);
         

        int posDansVectCaseMap{0};
        for(int i{0}; i<10; i++) {
            for(int j{0}; j<10; j++) {
                // rendu case 54x54
                glPushMatrix();
                // décalage de case (0->9)
                glTranslatef(0.2f*i, -0.2f*j, 0.f);
                // draw_square(VectCaseMap[posDansVectCaseMap].R, VectCaseMap[posDansVectCaseMap].G, VectCaseMap[posDansVectCaseMap].B);
                if(VectCaseMap[posDansVectCaseMap].typeDeCase == typeCase::chemin) {
                    // Si la case de gauche et la case de droite sont des chemins
                    if(VectCaseMap[posDansVectCaseMap-10].typeDeCase == typeCase::chemin && VectCaseMap[posDansVectCaseMap+10].typeDeCase == typeCase::chemin) {
                        // Si haut chemin
                        if(VectCaseMap[posDansVectCaseMap-1].typeDeCase == typeCase::chemin) {
                                draw_quad_with_texture(tiles_textures[typeCase::chemin_T_inverse]);
                        }
                        // Si bas chemin
                        else if(VectCaseMap[posDansVectCaseMap+1].typeDeCase == typeCase::chemin) {
                                draw_quad_with_texture(tiles_textures[typeCase::chemin_T]);
                        }
                        else {
                            draw_quad_with_texture(tiles_textures[typeCase::chemin_horizontal]);
                        }
                    }
                    else if(VectCaseMap[posDansVectCaseMap-10].typeDeCase == typeCase::chemin) {
                        if(VectCaseMap[posDansVectCaseMap-1].typeDeCase == typeCase::chemin && VectCaseMap[posDansVectCaseMap+1].typeDeCase == typeCase::chemin) {
                            draw_quad_with_texture(tiles_textures[typeCase::chemin_T_gauche]);
                        }
                        else if(VectCaseMap[posDansVectCaseMap-1].typeDeCase == typeCase::chemin) {
                            draw_quad_with_texture(tiles_textures[typeCase::chemin_haut_gauche]);
                        }
                        else {
                            draw_quad_with_texture(tiles_textures[typeCase::chemin_gauche_bas]);
                        }
                    }
                    else if(VectCaseMap[posDansVectCaseMap+10].typeDeCase == typeCase::chemin) {
                        if(VectCaseMap[posDansVectCaseMap-1].typeDeCase == typeCase::chemin || VectCaseMap[posDansVectCaseMap-1].typeDeCase == typeCase::chemin_depart) {
                            draw_quad_with_texture(tiles_textures[typeCase::chemin_haut_droite]);
                        }
                        else {
                            draw_quad_with_texture(tiles_textures[typeCase::chemin_droite_bas]);
                        }
                    }
                    else {
                        draw_quad_with_texture(tiles_textures[typeCase::chemin_vertical]);
                    }
                }
                else if(VectCaseMap[posDansVectCaseMap].typeDeCase == typeCase::nonchemin) {
                    int numero = (i*j)%3;
                    if(numero==0) {
                        draw_quad_with_texture(tiles_textures[typeCase::nonchemin_1]);
                    }
                    if(numero==1) {
                        draw_quad_with_texture(tiles_textures[typeCase::nonchemin_2]);
                    }
                    if(numero==2) {
                        draw_quad_with_texture(tiles_textures[typeCase::nonchemin_3]);
                    }                
                }
                else {
                draw_quad_with_texture(tiles_textures[VectCaseMap[posDansVectCaseMap].typeDeCase]);
                }
                glPopMatrix();
                posDansVectCaseMap++;
            }
        }

        // déplacement du repère en haut à gauche
        glTranslatef(-1.f, -1.f, 0.f);



        for (unsigned long i = 0; i < this->ennemis.size(); i++){

            glPushMatrix();

            // déplacement du repère en haut à gauche
            glTranslatef(this->ennemis.at(i).posX*0.2f+1, -this->ennemis.at(i).posY*0.2f+1, 0.f);
            draw_quad_with_texture(ennemis_textures[this->ennemis.at(i)._typeEnnemi]);
            glTranslatef(-this->ennemis.at(i).posX*0.2f+1, this->ennemis.at(i).posY*0.2f-1, 0.f);


            glPopMatrix();
        }

        //TextRenderer.Label("Jolie map tavu", _width / 2, 20, SimpleText::CENTER);
        TextRenderer.Label("Appuyez sur la touche T", _width / 50, 100, SimpleText::LEFT);
        TextRenderer.Label("pour placer les 3 Tours", _width / 50, 115, SimpleText::LEFT);
        TextRenderer.Label("Appuyez sur la touche Y", _width / 50, 140, SimpleText::LEFT);
        TextRenderer.Label("pour voir les zones de dommages des Tours", _width / 50, 155, SimpleText::LEFT);

        // Without set precision
        // const std::string angle_label_text { "Angle: " + std::to_string(_angle) };
        // With c++20 you can use std::format
        // const std::string angle_label_text { std::format("Angle: {:.2f}", _angle) };

        // Using stringstream to format the string with fixed precision
        // std::string angle_label_text {};
        // std::stringstream stream {};
        // stream << std::fixed << "Angle: " << std::setprecision(2) << _angle;
        // angle_label_text = stream.str();

        // TextRenderer.Label(angle_label_text.c_str(), _width / 2, _height - 4, SimpleText::CENTER);

        TextRenderer.Render();


        // cursor_position_callback - Affichage placement des Tours
        const float aspectRatio { _width / (float) _height };

        xposTourVerif = ((float)xposCursor-(((float)_width-_height)/2))*(1080.f/_height);
        yposTourVerif = yposCursor*(1080.f/_height);

        glTranslatef(1.f, 1.f, 0.f);

        if(ActionPlacementTour==1 && CompteurPlacementTour!=6) {
            // std::cout << " Compteur Placement Tour = " << CompteurPlacementTour << std::endl;
            glPushMatrix();
                glTranslatef((float)xposTourVerif/540, -(float)yposTourVerif/540, 0.f);
                if(CompteurPlacementTour==0) {
                    draw_quad_with_tower(tours_textures[typeTour::archer]);
                    if(ZoneDegatTour==1) {
                        dessineZoneDegats(1.f,0.f,1.f);
                    }
                }
                if(CompteurPlacementTour==2) {
                    draw_quad_with_tower(tours_textures[typeTour::chevalier]);
                    if(ZoneDegatTour==1) {
                        dessineZoneDegats(1.f,0.f,1.f);
                    }
                } 
                if(CompteurPlacementTour==4) {
                    draw_quad_with_tower(tours_textures[typeTour::sorcier]);
                    if(ZoneDegatTour==1) {
                        dessineZoneDegats(1.f,0.f,1.f);
                    }
                }
            glPopMatrix();
        }

        // mouse_button_callback - Affichage courant des Tours
        if(CompteurPlacementTour>=1) {
            glPushMatrix();
                xposTour1 = calibrageTour(xposTour1);
                yposTour1 = calibrageTour(yposTour1);
                glTranslatef((float)xposTour1/540, -(float)yposTour1/540, 0.f);
                draw_quad_with_tower(tours_textures[typeTour::archer]);
                if(ZoneDegatTour==1) {
                    dessineZoneDegats(1.f,0.f,1.f);
                }
            glPopMatrix();
        }
        if(CompteurPlacementTour>=3) {
            glPushMatrix();
                xposTour2 = calibrageTour(xposTour2);
                yposTour2 = calibrageTour(yposTour2);
                glTranslatef((float)xposTour2/540, -(float)yposTour2/540, 0.f);
                draw_quad_with_tower(tours_textures[typeTour::chevalier]);
                if(ZoneDegatTour==1) {
                    dessineZoneDegats(1.f,0.f,1.f);
                }
            glPopMatrix();
        }
        if(CompteurPlacementTour>=5) {
            glPushMatrix();
                xposTour3 = calibrageTour(xposTour3);
                yposTour3 = calibrageTour(yposTour3);
                glTranslatef((float)xposTour3/540, -(float)yposTour3/540, 0.f);
                draw_quad_with_tower(tours_textures[typeTour::sorcier]);
                if(ZoneDegatTour==1) {
                    dessineZoneDegats(1.f,0.f,1.f);
                }
            glPopMatrix();
        }
        


    } else {
        // Clear the color and depth buffers of the frame buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        TextRenderer.Label("Appuyez sur la touche", _width / 2, _height / 2 - 50, SimpleText::CENTER);
        TextRenderer.Label("S", _width / 2, _height / 2, SimpleText::CENTER);
        TextRenderer.Label("pour jouer", _width / 2, _height / 2 + 50, SimpleText::CENTER);
        TextRenderer.Render();
    }
}

void App::tick(int tick){
    if (tick==1){
        this->moveEnnemies();
    }

    if (tick==4){
        std::random_device rd;
        // Initialize a Mersenne Twister pseudo-random generator with the random device
        std::mt19937 gen(rd());
        // Create a uniform distribution for integers between 1 and 20 (inclusive)
        std::uniform_int_distribution<> distr(1, 4);
        

        // Generate a random number
        int random_number = distr(gen);

        if (random_number==2)populate();

    }
}

void App::moveEnnemies(){

    int size = this->ennemis.size();

    for (int i = 0; i < size ; i++){
        
        if (this->ennemis.at(i).posX == endX && this->ennemis.at(i).posY == endY){
            this->ennemis.erase(this->ennemis.begin() + i);

            i--;
            size--;
            continue;
        }

        for (int j = 0; j < (int) this->path.size()-1; j++){
            if (this->ennemis.at(i).posX == this->path.at(j).first && this->ennemis.at(i).posY == this->path.at(j).second){
                this->ennemis.at(i).posX = this->path.at(j+1).first;
                this->ennemis.at(i).posY = this->path.at(j+1).second;
                break;
            }
        }
    }
}

std::vector<Case*> App::getNeighbors(Case* node) {
    std::vector<Case*> neighbors;
    int x = node->posx;
    int y = node->posy;

    // Add neighboring cells (assuming 4-directional movement)
    if (x > 0) neighbors.push_back(&map2d[y - 1][x]);
    if (x < (int)map2d.size() - 1) neighbors.push_back(&map2d[y + 1][x]);
    if (y > 0) neighbors.push_back(&map2d[y][x - 1]);
    if (y < (int)map2d[0].size() - 1) neighbors.push_back(&map2d[y][x + 1]);

    return neighbors;
}

std::vector<std::pair<int, int>> App::calculatePath(int startX, int startY, int endX, int endY) {
    std::cout << "1";
    if (map2d.empty()) return {};

    //auto compare = [](Case* a, Case* b) { return a->f > b->f; };
    std::priority_queue<Case*, std::vector<Case*>, CompareF> openSet;
    std::unordered_set<Case*> closedSet;
    std::cout << "2";

    Case* startNode = &map2d[startX][startY];
    Case* endNode = &map2d[endX][endY];

    startNode->g = 0;
    startNode->h = heuristic(startX, startY, endX, endY);
    startNode->f = startNode->g + startNode->h;
    openSet.push(startNode);

    std::cout << "3";

    while (!openSet.empty()) {
        Case* current = openSet.top();
        openSet.pop();

        if (current == endNode) {
            std::vector<std::pair<int, int>> path;
            while (current != nullptr) {
                path.push_back({ current->posx, current->posy });
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        closedSet.insert(current);

        for (Case* neighbor : getNeighbors(current)) {
            if (closedSet.find(neighbor) != closedSet.end() || neighbor->typeDeCase == typeCase::nonchemin) {
                continue;
            }

            int tentative_gScore = current->g + 1; // assuming each move costs 1

            // if (tentative_gScore < neighbor->g) {
            //     neighbor->parent = current;
            //     neighbor->g = tentative_gScore;
            //     neighbor->h = heuristic(neighbor->posx, neighbor->posy, endX, endY);
            //     neighbor->f = neighbor->g + neighbor->h;

            //     openSet.push(neighbor);
            // }
        }
    }

    return {}; // Return empty path if no path is found
}


void App::key_callback(int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
	    if(JeuStart == 0) {
			JeuStart = 1;
        }
	if (key == GLFW_KEY_T && action == GLFW_PRESS)
		if(ActionPlacementTour == 0) {
			ActionPlacementTour = 1;
        } else {
            ActionPlacementTour = 0;
        }
	if (key == GLFW_KEY_Y && action == GLFW_PRESS)
		if(ZoneDegatTour == 0) {
			ZoneDegatTour = 1;
        } else {
            ZoneDegatTour = 0;
        }
}

void App::mouse_button_callback(int button, int action, int mods) {

    std::vector<Case> VectPixelMap{};
    VectPixelMap = VerifPlacementTourVectMap(&map1080x1080);
    // std::cout << " Composante R du pixel = " << VectPixelMap[(xposTourVerif*1080)+yposTourVerif].R << std::endl;
    
    if(VectPixelMap[(xposTourVerif*1080)+yposTourVerif].G!=0 && VectPixelMap[(xposTourVerif*1080)+yposTourVerif].R!=255 && ActionPlacementTour==1) {
        if(CompteurPlacementTour<7) {
            CompteurPlacementTour++;
            if(CompteurPlacementTour==1) {
                xposTour1 = xposTourVerif;
                yposTour1 = yposTourVerif;
            }
            if(CompteurPlacementTour==3) {
                xposTour2 = xposTourVerif;
                yposTour2 = yposTourVerif;
            }
            if(CompteurPlacementTour==5) {
                xposTour3 = xposTourVerif;
                yposTour3 = yposTourVerif;
            }
        }
    }
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/) {
}

void App::cursor_position_callback(double xpos, double ypos) {

    xposCursor = xpos;
    yposCursor = ypos;

}

void App::size_callback(int width, int height) {

    _width  = width;
    _height = height;

    // make sure the viewport matches the new window dimensions
    glViewport(0, 0, _width, _height);

    const float aspectRatio { _width / (float) _height };

    // Change the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(aspectRatio > 1.0f) {
        glOrtho(-_viewSize / 2.0f * aspectRatio, _viewSize / 2.0f * aspectRatio, -_viewSize / 2.0f, _viewSize / 2.0f, -1.0f, 1.0f);
    } else {
        glOrtho(-_viewSize / 2.0f, _viewSize / 2.0f, -_viewSize / 2.0f / aspectRatio, _viewSize / 2.0f / aspectRatio, -1.0f, 1.0f);
    }


}





// Autres fonctions

void App::populate(){
    std::random_device rd;
    // Initialize a Mersenne Twister pseudo-random generator with the random device
    std::mt19937 gen(rd());
    // Create a uniform distribution for integers between 1 and 20 (inclusive)
    std::uniform_int_distribution<> distr(1, 3);
    

    // Generate a random number
    int random_number = distr(gen);

    if (random_number == 1) this->ennemis.push_back(Ennemi(startX, startY, typeEnnemi::colin));
    if (random_number == 2) this->ennemis.push_back(Ennemi(startX, startY, typeEnnemi::milan));
    if (random_number == 3) this->ennemis.push_back(Ennemi(startX, startY, typeEnnemi::elisabeth));
}

void App::preCalculation(){
    short sx {-1};
    short sy {-1};

    short ex {-1};
    short ey {-1};

    for (short i=0; i < 10; i++){
        for (short j=0; j < 10; j++){
            if (this->map2d.at(i).at(j).typeDeCase == typeCase::chemin_depart){
                sx = j;
                sy = i;
            }

            if (this->map2d.at(i).at(j).typeDeCase == typeCase::chemin_arrivee){
                ex = j;
                ey = i;
            }
        }
    }

    this->startX = sx;
    this->startY = sy;
    this->endX = ex;
    this->endY = ey;

    //this->path = calculatePath(sx,sy,1,0);
    this->path = {{5,9},{5,8},{5,7},{6,7},{7,7},{7,6},{8,6},{8,5},{8,4}, {7,4},{6,4},{6,3},{6,2},{7,2}, {7,1}, {7,0}};

    // std::cout << "AHA" << std::endl;
    // for (int i = 0; i < (int)this->path.size(); i++){
    //     std::cout << this->path.at(i).first << "/" << this->path.at(i).second << std::endl;
    // }
}