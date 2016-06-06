<?php
	header("Content-type: text/json");

	$file = file('coor.txt');
	$ligne = $file[count($file)-1];
	$n = sscanf($ligne,"%f,%f;%f,%f",$x1,$y1,$x2,$y2);
	$res=array($x1,$y1,$x2,$y2);
	echo json_encode($res);
	
?>
