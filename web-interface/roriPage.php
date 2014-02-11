<html>
<head>
<title>Home</title>
<link rel="stylesheet" href="css/style.css" />
</head>
<body>
<?php
//TODO : faire un meilleur système de session + hashage
$User=addslashes($_POST['username']);
$Pass=addslashes($_POST['password']); 

if($User == "demo" && $Pass == "demo")
   echo("hei demo !");
else
   echo("Accès non authorisé");
?>
</body>
</html>
