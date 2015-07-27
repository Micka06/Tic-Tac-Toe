#include "fenetre.h"

Fenetre::Fenetre() : joueur1(true), case1(true), case2(true), case3(true), case4(true), case5(true), case6(true), case7(true), case8(true), case9(true)
{
    //Gestion des images
    chargerFichiers();

    //Gestion Fenetre
    window.create(sf::VideoMode(450,550,32), "Tic-Tac-Toe by Mickael");
    window.setFramerateLimit(60);
    window.setIcon(64,64,icone.getPixelsPtr());


    while(window.isOpen())
    {

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                spriteAPropos.setPosition(0,0);
            }else{
                spriteAPropos.setPosition(1000,0);
            }
        }

        //GESTION SOURIS / Affichage des indications du joueur qui doit jouer
        if(joueur1)
        {
            if(!texteJoueur.loadFromFile("Images/joueur1.png"))
                std::cout << "ERREUR : Impossible de charger l'image : \"Images/joueur1.png\"" << std::endl;
            spriteTexteJouer.setTexture(texteJoueur);
            spriteTexteJouer.setPosition(sf::Vector2f(37.8f,453.7f));
            gestionSouris(joueur1);
        }
        else
        {
            if(!texteJoueur.loadFromFile("Images/joueur2.png"))
                std::cout << "ERREUR : Impossible de charger l'image : \"Images/joueur2.png\"" << std::endl;
            spriteTexteJouer.setTexture(texteJoueur);
            spriteTexteJouer.setPosition(sf::Vector2f(37.8f,453.7f));
            gestionSouris(joueur1);
        }
        verif();


        window.clear(sf::Color::White);
        window.draw(spriteFond);
        window.draw(spriteTexteJouer);
        for(int i = 0; i < 9; i++)
            window.draw(spriteCercle[i]);
        for(int i = 0; i < 9; i++)
            window.draw(spriteCroix[i]);
        window.draw(gagne);
        window.draw(spriteAPropos);


        window.display();
    }
}

void Fenetre::chargerFichiers()
{
    //Chargement Fond d'écran
    if(!fond.loadFromFile("Images/fondVide.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/fondVide.png\"" << std::endl;
    spriteFond.setTexture(fond);

    //Icone
    if(!icone.loadFromFile("Images/icone.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/icone.png\"" << std::endl;

    //Signes
    if(!cercle.loadFromFile("Images/cercle.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/cercle.png\"" << std::endl;
    if(!croix.loadFromFile("Images/croix.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/croix.png\"" << std::endl;

    //Ecrans quand un joueur gagne
    if(!joueur1Gagne.loadFromFile("Images/joueur1Gagne.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/joueur1Gagne.png\"" << std::endl;
    if(!joueur2Gagne.loadFromFile("Images/joueur2Gagne.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/joueur2Gagne.png\"" << std::endl;

    //Sons
    if(!clique.loadFromFile("Audio/clique.ogg"))
        std::cout << "ERREUR : Impossible de charger le son : \"Audio/clique.ogg\"" << std::endl;
    bruitClique.setBuffer(clique);
    bruitClique.setVolume(60);
    if(!music.openFromFile("Audio/debardage.ogg"))
        std::cout << "ERREUR : Impossible d'ouvrir la musique : \"Audio/debardage.ogg\"" << std::endl;
    music.play();
    music.setLoop(true);
    music.setVolume(80);

    //A Propos
    if(!aPropos.loadFromFile("Images/apropos.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/apropos.png\"" << std::endl;
    spriteAPropos.setTexture(aPropos);

    //Match Nul
    if(!matchNul.loadFromFile("Images/matchnul.png"))
        std::cout << "ERREUR : Impossible de charger l'image : \"Images/matchnul.png\"" << std::endl;
}

void Fenetre::gestionSouris(bool joueur)
{
    posSouris = sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 0 && posSouris.x < 150) && (posSouris.y > 0 && posSouris.y < 150)) && case1)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[0].setPosition(0,0);
            spriteCercle[0].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[0].setPosition(0,0);
            spriteCroix[0].setTexture(croix);
            joueur1 = true;
        }
        case1 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 150 && posSouris.x < 300) && (posSouris.y > 0 && posSouris.y < 150)) && case2)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[1].setPosition(150,0);
            spriteCercle[1].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[1].setPosition(150,0);
            spriteCroix[1].setTexture(croix);
            joueur1 = true;
        }
        case2 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 300 && posSouris.x < 450) && (posSouris.y > 0 && posSouris.y < 150)) && case3)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[2].setPosition(300,0);
            spriteCercle[2].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[2].setPosition(300,0);
            spriteCroix[2].setTexture(croix);
            joueur1 = true;
        }
        case3 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 0 && posSouris.x < 150) && (posSouris.y > 150 && posSouris.y < 300)) && case4)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[3].setPosition(0,150);
            spriteCercle[3].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[3].setPosition(0,150);
            spriteCroix[3].setTexture(croix);
            joueur1 = true;
        }
        case4 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 150 && posSouris.x < 300) && (posSouris.y > 150 && posSouris.y < 300)) && case5)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[4].setPosition(150,150);
            spriteCercle[4].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[4].setPosition(150,150);
            spriteCroix[4].setTexture(croix);
            joueur1 = true;
        }
        case5 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 300 && posSouris.x < 450) && (posSouris.y > 150 && posSouris.y < 300)) && case6)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[5].setPosition(300,150);
            spriteCercle[5].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[5].setPosition(300,150);
            spriteCroix[5].setTexture(croix);
            joueur1 = true;
        }
        case6 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 0 && posSouris.x < 150) && (posSouris.y > 300 && posSouris.y < 450)) && case7)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[6].setPosition(0,300);
            spriteCercle[6].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[6].setPosition(0,300);
            spriteCroix[6].setTexture(croix);
            joueur1 = true;
        }
        case7 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 150 && posSouris.x < 300) && (posSouris.y > 300 && posSouris.y < 450)) && case8)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[7].setPosition(150,300);
            spriteCercle[7].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[7].setPosition(150,300);
            spriteCroix[7].setTexture(croix);
            joueur1 = true;
        }
        case8 = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ((posSouris.x > 300 && posSouris.x < 450) && (posSouris.y > 300 && posSouris.y < 450)) && case9)
    {
        if(joueur)
        {
            bruitClique.play();
            spriteCercle[8].setPosition(300,300);
            spriteCercle[8].setTexture(cercle);
            joueur1 = false;
        }
        else
        {
            bruitClique.play();
            spriteCroix[8].setPosition(300,300);
            spriteCroix[8].setTexture(croix);
            joueur1 = true;
        }
        case9 = false;
    }

}

void Fenetre::verif()
{
    //Joueur 1 Gagne
    if((spriteCercle[0].getTexture() != NULL && spriteCercle[1].getTexture() != NULL && spriteCercle[2].getTexture() != NULL) ||
            (spriteCercle[3].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[5].getTexture() != NULL) ||
            (spriteCercle[6].getTexture() != NULL && spriteCercle[7].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCercle[3].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCercle[1].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[7].getTexture() != NULL) ||
            (spriteCercle[2].getTexture() != NULL && spriteCercle[5].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCercle[2].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[6].getTexture() != NULL))
    {
        bruitClique.stop();
        music.stop();
        gagne.setTexture(joueur1Gagne);
    }

    //Joueur 2 gagne
    else if((spriteCroix[0].getTexture() != NULL && spriteCroix[1].getTexture() != NULL && spriteCroix[2].getTexture() != NULL) ||
            (spriteCroix[3].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[5].getTexture() != NULL) ||
            (spriteCroix[6].getTexture() != NULL && spriteCroix[7].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCroix[3].getTexture() != NULL && spriteCroix[6].getTexture() != NULL) ||
            (spriteCroix[1].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[7].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCroix[5].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[6].getTexture() != NULL))
    {
        music.stop();
        bruitClique.stop();
        gagne.setTexture(joueur2Gagne);
    }

    //Egalité
    else if(((spriteCercle[0].getTexture() != NULL && spriteCroix[1].getTexture() != NULL && spriteCercle[2].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCroix[1].getTexture() != NULL && spriteCroix[2].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCercle[1].getTexture() != NULL && spriteCroix[2].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCroix[1].getTexture() != NULL && spriteCercle[2].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCercle[1].getTexture() != NULL && spriteCercle[2].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCercle[1].getTexture() != NULL && spriteCroix[2].getTexture() != NULL)) &&
            ((spriteCercle[3].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[5].getTexture() != NULL) ||
            (spriteCercle[3].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[5].getTexture() != NULL) ||
            (spriteCercle[3].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[5].getTexture() != NULL) ||
            (spriteCroix[3].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[5].getTexture() != NULL) ||
            (spriteCroix[3].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[5].getTexture() != NULL) ||
            (spriteCroix[3].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[5].getTexture() != NULL)) &&
            ((spriteCercle[6].getTexture() != NULL && spriteCroix[7].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCercle[6].getTexture() != NULL && spriteCroix[7].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCercle[6].getTexture() != NULL && spriteCercle[7].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCroix[6].getTexture() != NULL && spriteCroix[7].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCroix[6].getTexture() != NULL && spriteCercle[7].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCroix[6].getTexture() != NULL && spriteCercle[7].getTexture() != NULL && spriteCroix[8].getTexture() != NULL)) &&
            ((spriteCercle[0].getTexture() != NULL && spriteCroix[3].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCroix[3].getTexture() != NULL && spriteCroix[6].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCercle[3].getTexture() != NULL && spriteCroix[6].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCroix[3].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCercle[3].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCercle[3].getTexture() != NULL && spriteCroix[6].getTexture() != NULL)) &&
            ((spriteCercle[1].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[7].getTexture() != NULL) ||
            (spriteCercle[1].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[7].getTexture() != NULL) ||
            (spriteCercle[1].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[7].getTexture() != NULL) ||
            (spriteCroix[1].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[7].getTexture() != NULL) ||
            (spriteCroix[1].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[7].getTexture() != NULL) ||
            (spriteCroix[1].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[7].getTexture() != NULL)) &&
            ((spriteCercle[2].getTexture() != NULL && spriteCroix[5].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCercle[2].getTexture() != NULL && spriteCroix[5].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCercle[2].getTexture() != NULL && spriteCercle[5].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCroix[5].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCercle[5].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCercle[5].getTexture() != NULL && spriteCroix[8].getTexture() != NULL)) &&
            ((spriteCercle[0].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCercle[0].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[8].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[8].getTexture() != NULL) ||
            (spriteCroix[0].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[8].getTexture() != NULL)) &&
            ((spriteCercle[2].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCercle[2].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCroix[6].getTexture() != NULL) ||
            (spriteCercle[2].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[6].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCroix[4].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCercle[6].getTexture() != NULL) ||
            (spriteCroix[2].getTexture() != NULL && spriteCercle[4].getTexture() != NULL && spriteCroix[6].getTexture() != NULL)))
    {
        music.stop();
        bruitClique.stop();
        gagne.setTexture(matchNul);
    }
}
