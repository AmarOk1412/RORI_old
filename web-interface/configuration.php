<!DOCTYPE HTML>
<!--
	Based on prologue 1.2 by HTML5 UP
	html5up.net | @n33co
	Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
-->
<html>
	<head>
		<title>RORI configuration</title>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<meta name="description" content="Page de configuration du chatterbot RORI" />
		<meta name="keywords" content="AmarOk, AmarOk1412, projets, enconn, libre, développer, créer, chatterbot, modulable, open-source, mutli-plateformes" />
		<link href="http://fonts.googleapis.com/css?family=Source+Sans+Pro:200,300,400,600" rel="stylesheet" type="text/css" />
		<!--[if lte IE 8]><script src="js/html5shiv.js"></script><![endif]-->
		<script src="js/jquery.min.js"></script>
		<script src="js/skel.min.js"></script>
		<script src="js/skel-panels.min.js"></script>
		<script src="js/init.js"></script>
		<noscript>
			<link rel="stylesheet" href="css/skel-noscript.css" />
			<link rel="stylesheet" href="css/style.css" />
			<link rel="stylesheet" href="css/style-wide.css" />
		</noscript>
		<!--[if lte IE 9]><link rel="stylesheet" href="css/ie9.css" /><![endif]-->
		<!--[if lte IE 8]><link rel="stylesheet" href="css/ie8.css" /><![endif]-->
	</head>
	<body>

		<!-- Header -->
			<div id="header" class="skel-panels-fixed">

				<div class="top">

					<!-- Logo -->
						<div id="logo">
							<span class="image avatar48"><img src="images/avatar.jpg" alt="" /></span>
								<h1 id="title">	

<?php
$file = fopen('./config/userProfil.inf','r');
$i = 0;
$nom = "";
$prenom = "";
while (!feof($file)) {
  $line = fgets($file);
  $i++;
  if($i == 9) {
    $nom = $line;
  }
  if($i == 10) {
    $prenom = $line;
  }
}
fclose($fh);
echo(strtoupper($nom).' '.$prenom);
?>							</h1>
							<span class="byline">Configuration de RORI</span>
						</div>

					<!-- Nav -->
						<nav id="nav">
							<!--
							
								Prologue's nav expects links in one of two formats:
								
								1. Hash link (scrolls to a different section within the page)
								
								   <li><a href="#foobar" id="foobar-link" class="skel-panels-ignoreHref"><span class="fa fa-whatever-icon-you-want">Foobar</span></a></li>

								2. Standard link (sends the user to another page/site)

								   <li><a href="http://foobar.tld"><span class="fa fa-whatever-icon-you-want">Foobar</span></a></li>
							
							-->
							<ul>
								<li><a href="#top" id="top-link" class="skel-panels-ignoreHref"><span class="fa fa-home">Introduction</span></a></li>
								<li><a href="#config" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Config</span></a></li>
								<li><a href="#files" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Files</span></a></li>
								<li><a href="#function" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Function</span></a></li>
								<li><a href="#regex" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Regex</span></a></li>
								<li><a href="#wordDir" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">wordDir</span></a></li>
								<li><a href="#about" id="about-link" class="skel-panels-ignoreHref"><span class="fa fa-user">About RORI</span></a></li>
							</ul>
						</nav>
						
				</div>
				
				<div class="bottom">

					<!-- Social Icons -->
						<ul class="icons">
							<li><a href="http://twitter.com/AmarOk1412" class="fa fa-twitter solo"><span>Twitter</span></a></li>
							<li><a href="https://www.github.com/AmarOk1412" class="fa fa-github solo"><span>Github</span></a></li>
							<li><a href="mailto:blin.sebastien@enconn.fr" class="fa fa-envelope solo"><span>Email</span></a></li>
						</ul>
				
				</div>
			
			</div>

		<!-- Footer -->
			<div id="footer">
				
				<!-- Copyright -->
					<div class="copyright">
						<ul class="menu">
							<li>Design: <a href="http://html5up.net">HTML5 UP</a></li>
							<li>Redesign: <a href="http://enconn.fr">AmarOk1412</a></li>
						</ul>
					</div>
				
			</div>

	</body>
</html>
