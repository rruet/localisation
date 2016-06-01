<?php
require_once("include_path_inc.php");

require_once("jpgraph.php");
require_once("jpgraph_scatter.php");

$donnees = array(12,23,9,58,23,26,57,48,12);

$largeur = 750;
$hauteur = 700;

// Initialisation du graphique
$graphe = new Graph($largeur, $hauteur);
// Echelle lineaire ('lin') en ordonnee et pas de valeur en abscisse ('text')
// Valeurs min et max seront determinees automatiquement
$graphe->setScale("textlin");

// Creation de l'histogramme
$histo = new ScatterPlot($donnees);
// Ajout de l'histogramme au graphique
$graphe->add($histo);

// Ajout du titre du graphique
$graphe->title->set("Histogramme");

// Affichage du graphique
$graphe->stroke();
?>
