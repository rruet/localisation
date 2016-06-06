<!DOCTYPE HTML>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Projet URGAN</title>

		<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<style type="text/css">
${demo.css}
		</style>
		<script type="text/javascript">

var chart;

//Cette fonction rafraichit les valeurs des coordonnees des badges avec celles
//contenues dans le fichier coor.txt, lui me traité par le script traitement.php

function refreshval(){
	$.ajax({
		url: 'traitement.php',
		success: function(point){
			var serie1 = chart.series[1],
			serie2 = chart.series[2],
			point1=[point[0],point[1]],
			point2=[point[2],point[3]],
			shift1 = serie1.data.length > 1,
			shift2 = serie2.data.length > 1;
	
			serie1.points[0].update({x: point[0], y: point[1]}, true, {duration : 750, easing: 'linear'});

			serie2.points[0].update({x: point[2], y: point[3]}, true, {duration : 750, easing: 'linear'});
			setTimeout(refreshval,3000);
		},
		cache: false
	});
}

//On crée le nuage de points qui représentera les positions des balises (fixes) et des badges (dynamiques)

$(document).ready(function () {

	chart= new Highcharts.Chart({
		chart:{
			renderTo: 'container', //graphe insere dans la balise 'container' du script html
			type: 'scatter',
			zoomtype: 'xy',
			events: { load: refreshval }
		},
		title: {
			text: 'Localisation Indoor IRCICA'
		},
		subtitle: {
			text: 'projet URGAN'
		},
		xAxis: {
			startOnTick :true,
			endOnTick: true,
		},
		plotOptions: {
			scatter: {
				marker: {
					radius:7
				}
			}
		},
		series: [{
			name: 'balises', //positions des balises
			color: 'black',
			data: [[0,0],[0,4],[7,0],[7,4]]
			},
			{
			name: 'badge1', //a partir d'ici, les coordonnées des badges
			color: 'blue',
			data : [[0,0]]
			},
			{
			name: 'badge2',
			color: 'green',
			data: [[0.0]]
			}]
	});
});


		</script>
	</head>
	<body>
		<script src="https://code.highcharts.com/highcharts.js"></script>

		<div id="container" style="min-width: 500px; height:500px; max-width: 800px; margin:0 auto"></div> 
	</body>
</html>
