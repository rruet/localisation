<?php
	header("Content-type: text/json");

	$file = file('coor.txt');
	$ligne = $file[count($file)-1];
	$n = sscanf($ligne,"%f,%f",$x,$y);
	$res=array($x,$y);
	echo json_encode($res);
	
?>
