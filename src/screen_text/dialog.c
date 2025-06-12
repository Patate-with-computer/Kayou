/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** dialog.c
*/

/// @brief intro dialog (if the save dosent exist)
const char intro_txt[] = ""
    "Annee 4XXX du calendrier aqua-lunaire - 1X ans apres la"
    " grande catastrophe.\n"
    "Suite a l'arrivee des Poulpovores, tout droit "
    "venus des abysses, le peuple des hommes-cailloux "
    "fut quasiment aneanti. En tant qu'homme-caillou, "
    "et suite a des modifications apportees a votre corps, "
    "vous permettant d'user de facultes des Poulpovores, vous "
    "avez ete envoye, dans leur derniere base d'operations, afin "
    "de recuperer celle-ci, et de tenter d'eliminer leurs plus forts "
    "guerriers. (certaines rumeurs suggereraient meme que leur chef "
    "supreme s'y trouverait).\n"
    "Apparemment, l'un de vos amis, ainsi que des civils se seraient "
    "perdus, ou auraient ete captures, et se trouveraient dans celle-ci.\n"
    "Equipe toi. Tire. Ne recule pas. Le monde a besoin de toi.\n"
    "Commandes:\n"
    "ZQSD - Se deplacer\n"
    "R/L1 - Changer d'arme  Espace/Click/R1 - tirer\n"
    "E/Croix - Ouvrir le magasin\n"
    "Echap/Options - Acceder au Menu\n"
    "A/Rond - Interragir avec les pnj /Afficher/ Quitter un texte";

/// @brief dialog for the pnj in the intro room
const char intro_pnj[] = ""
    "Cher voyageur, bienvenue dans cette premiere salle"
    ", tous les murs n'ont pas l'air solides..., si tu trouves mes freres"
    ", parle leur avec le A";
const char intro_pnj_enemy[] = ""
    "Noooooooon, j'ai cette tete mais je ne suis pas comme eux !!!";
const char intro_command[] = ""
    "Rappelle toi de ces commandes: "
    "QZDS: Se deplacer, "
    "R/L1: Changer d'arme, "
    "E/Croix: magasin, "
    "Echap/Options: Menu, "
    "A/Rond: Interraction, "
    "Espace/Click/R1: tirer";

/// @brief dialog for the labyrinth room
const char lab_turn_pnj[] = ""
    "Generalement je prends plutot a gauche, avec mes amis"
    " et a droite pour aller au travail.";
const char good_ending[] = ""
    "Peux tu me dire ce qu'il se trouve derriere ces planches ?";
const char wrong_way[] = ""
    "Aie Aie Aie, c'est pas du tout par la, "
    "je peux te raconter une histoire cependant..."
    " Ah ! Tu es presse, je vois. Bonne continuation alors :)";
const char hello[] = ""
    "Bonjour !";

/// @brief dialog in the hell room
const char dont_like[] = ""
    "Je n'aime pas trop le brouillard, il reduit ta visibilite"
    " mais pas celle de ces Poulpovores, j'ai un peu peur il y"
    " en a plusieur par ici, aide-moi s'il te plait.";

const char visibilty[] = ""
    "Tu gardes tout de meme une bonne visibilite"
    ", j'ai appris qu'il y avait des endroits pleins de pieces d'or. "
    "Cette minimap m'avait autrefois aide.";

const char plank[] = ""
    "Merci de m'avoir libere. "
    "De ce que j'ai entendu, certaines planches ici, auraient mute, "
    "et attaqueraient maintenant tout ce qu'elles voient.";

const char golDsquid[] = ""
    "Merci de m'avoir libere. "
    "Mon tresor? Il est la ou je l'ai laisse. Il est a vous si "
    "vous pouvez le trouver... Mais vous aurez a chercher toute la salle!";

const char warning[] = ""
    "Je ne te veux pas de mal, je suis un agent infiltre. "
    "Fais attention, leur plus fort guerrier se trouve juste a cote. "
    "Je n'aime pas me battre, donc je reste ici.";


/// @brief dialog in the demo
const char break_the_wall[] = ""
    "Salut, les murs devant toi sont cassables, tire dessus"
    " avec espace (ou clique gauche). (P.S: tous les murs cassables"
    " ne sont pas forcement des planches)";
const char there_is_shadow[] = ""
    "Attention, lorsque tu franchiras cette porte, la lumiere "
    "s'eteindra, tu ne pourras compter que "
    "sur ta lampe torche et ton courage !";
const char there_is_fog[] = ""
    "Il fait sombre mais attention a la brume, "
    "apres cette porte la brume tombera.";
const char there_is_item[] = ""
    "Bravo, tu as fait beaucoup de chemin ! Maintenant il faut se "
    "ravitailler, tu trouveras plus loin de la vie, "
    "des munitions et de la magie.";
const char there_is_enemy[] = ""
    "Je me suis fait toucher, fais tres attention a toi, "
    "les Poulpovores sont sans pitie. (P.S: il me semble"
    " que le pistolet coute 50$)";
const char end_first_phase[] = ""
    "Bravo, tu as passe la premiere phase !! "
    "Cependant attention, il en arrive des plus forts...";
const char end_second_phase[] = ""
    "Bravo, tu as passe la deuxieme phase !! "
    "Celui ci va bien plus vite, fait attention a toi.";
const char end_last_phase[] = ""
    "Bravo, tu as passe la troisieme phase !! "
    "Un combot des meilleurs Poulpovores arrive droit sur toi, "
    "reste vigilent";
