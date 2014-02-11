<html>
<head>
<title>Home</title>
<link rel="stylesheet" href="css/style.css" />
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
</head>
<body>
<?php
//TODO : faire un meilleur système de session + hashage
$User=addslashes($_POST['username']);
$Pass=addslashes($_POST['password']); 

if($User == "demo" && $Pass == "demo")
{
   echo('<ul class="left-menu">
	    <li>
		<a href="">
		    <img src="images/modules.png" alt="modules" />
		</a>
	    </li>
	    <li>
		<a href="">
		    <img src="images/connect.png" alt="connect" />
		</a>
	    </li>
	    <li>
		<a href="">
		    <img src="images/params.png" alt="parametres" />
		</a>
	    </li>
</ul>
<div id="content">
<form action="<?=$PHP_SELF?>" method="POST">
<textarea name="history">
');


	if($_POST['addition']){
		$file_open = fopen("history","w+");
		fwrite($file_open, $_POST['addition']);
		fclose($file_open);
	}
	$datalines = file ("history");

	foreach ($datalines as $zz) 
	    echo $zz;

	echo('</textarea>

	<input type="submit" name="button">
	    </form></div>');
}
else
   echo("Accès non authorisé");
?>
</body>
</html>
