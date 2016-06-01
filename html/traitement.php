<?php


	$tab = file('coor.txt');
	$ligne = $tab[count($tab)-1];
	//echo $ligne;
	//echo "</br>";	


	$n = sscanf($ligne,"%f %f\n",$x,$y);
	//echo $x;
	//echo "</br>";
	//echo $y;
	echo "<table border='1'>              
                        <Caption>Coordonn&eacute;es instantann&eacute;es</caption>
                                <TR> 
                                <TH>X</TH>         
                                <TH>Y</TH> 
                                </TR>
                                <TR>
                                <TD>'$x'</TD>         
                                <TD>'$y'</TD>          
                                </TR>   
                </table>";
?>
