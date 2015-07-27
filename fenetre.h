#ifndef FENETRE
#define FENETRE

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Fenetre
{
public:
    Fenetre();
    void chargerFichiers();
    void gestionSouris(bool joueur);
    void verif();

private:
    sf::RenderWindow window;
    sf::Texture fond;
    sf::Sprite spriteFond;
    sf::Image icone;
    bool joueur1;
    sf::Event event;
    sf::Vector2i posSouris;
    sf::Texture texteJoueur;
    sf::Sprite spriteTexteJouer;
    sf::Texture cercle;
    sf::Sprite spriteCercle[9];
    sf::Texture croix;
    sf::Sprite spriteCroix[9];
    bool case1;
    bool case2;
    bool case3;
    bool case4;
    bool case5;
    bool case6;
    bool case7;
    bool case8;
    bool case9;
    sf::Texture joueur1Gagne;
    sf::Texture joueur2Gagne;
    sf::Sprite gagne;
    bool replay;
    sf::SoundBuffer clique;
    sf::Sound bruitClique;
    sf::Music music;
    sf::Texture aPropos;
    sf::Sprite spriteAPropos;
    sf::Texture matchNul;
};

#endif // FENETRE

