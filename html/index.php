<!DOCTYPE HTML>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<META HTTP-EQUIV="PRAGMA" CONTENT="NO-CACHE">
		<title>Projet URGAN</title>

		<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<style type="text/css">
${demo.css}
		</style>
		<script type="text/javascript">

var chart;

function refreshval(){
	$.ajax({
		url: 'traitement.php',
		success: function(point){
			var series = chart.series[1],
			shift = series.data.length > 1;
	
			chart.series[1].removePoint(0,true,false);
			chart.series[1].addPoint(point, true, shift);

			setTimeout(refreshval,3000);
		},
		cache: false
	});
}

$(document).ready(function () {

	chart= new Highcharts.Chart({
		chart:{
			renderTo: 'container',
			type: 'scatter',
			zoomtype: 'xy',
			events: { load: refreshval }
		},
		title: {
			text: 'localisation indoor IRCICA'
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
			name: 'balises',
			color: 'black',
			data: [[0,0],[0,4],[7,0],[7,4]]
			},
			{
			name: 'badge1',
			color: 'blue',
			data : []
			},
			{
			name: 'badge2',
			color: 'green',
			data: [[4,0.5]]
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
