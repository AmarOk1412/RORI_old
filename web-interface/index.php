<!DOCTYPE HTML>
<!--
	Based on prologue 1.2 by HTML5 UP
	html5up.net | @n33co
	Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
-->
<html>
	<head>
		<title>RORI's Configuration</title>
                <link rel="icon" type="image/png" href="images/favicon.png">
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
							<span class="byline">RORI's Configuration</span>
						</div>

					<!-- Nav -->
						<nav id="nav">
							<ul>
								<li><a href="#top" id="top-link" class="skel-panels-ignoreHref"><span class="fa fa-home">Introduction</span></a></li>
								<li><a href="#config" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Config</span></a></li>
								<li><a href="#files" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Files</span></a></li>
								<li><a href="#function" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Function</span></a></li>
								<li><a href="#regex" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">Regex</span></a></li>
								<li><a href="#wordDir" id="portfolio-link" class="skel-panels-ignoreHref"><span class="fa fa-th">WordDir</span></a></li>
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

		<!-- Main -->
			<div id="main">
			
				<!-- Intro -->
					<section id="top" class="one">
						<div class="container">

							<a href="http://enconn.fr" class="image featured"><img src="images/header.png" alt="" /></a>

							<header>
								<h2 class="alt">This is <strong>RORI</strong>. A <a href="http://www.wtfpl.net/">free</a>, modulable and multi-platform <br />
								chatterbot created by <a href="http://enconn.fr">AmarOk1412</a>.</h2>
							</header>
							
							<p>RORI is a mix of a classic chatterbot and a domotic bot. It can does so many action like talk, control a mobile phone, a computer (you can surf on Internet with the voice). A RORI's server must run on a linux system (Computer/BeagleBone/Raspberry Pi). You can configure all the bot on this page.</p>

							<footer>
								<a href="#config" class="button scrolly">More Power !</a>
							</footer>

						</div>
					</section>
					
				<!-- Config -->
					<section id="config" class="two">
						<div class="container">
					
							<header>
								<h2>Portfolio</h2>
							</header>
							
							<p>Vitae natoque dictum etiam semper magnis enim feugiat convallis convallis
							egestas rhoncus ridiculus in quis risus amet curabitur tempor orci penatibus.
							Tellus erat mauris ipsum fermentum etiam vivamus eget. Nunc nibh morbi quis 
							fusce hendrerit lacus ridiculus.</p>
						
							<div class="row">
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/A-million-suns-384369739" class="image full"><img src="images/pic02.jpg" alt="" /></a>
										<header>
											<h3>Ipsum Feugiat</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Mind-is-a-clear-stage-375431607" class="image full"><img src="images/pic03.jpg" alt="" /></a>
										<header>
											<h3>Rhoncus Semper</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/You-really-got-me-345249340" class="image full"><img src="images/pic04.jpg" alt="" /></a>
										<header>
											<h3>Magna Nullam</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Ad-infinitum-354203162" class="image full"><img src="images/pic05.jpg" alt="" /></a>
										<header>
											<h3>Natoque Vitae</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Elysium-355393900" class="image full"><img src="images/pic06.jpg" alt="" /></a>
										<header>
											<h3>Dolor Penatibus</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Emperor-of-the-Stars-370265193" class="image full"><img src="images/pic07.jpg" alt="" /></a>
										<header>
											<h3>Orci Convallis</h3>
										</header>
									</article>
								</div>
							</div>

						</div>
					</section>

					<!-- Files -->
					<section id="files" class="two">
						<div class="container">
					
							<header>
								<h2>Portfolio</h2>
							</header>
							
							<p>Vitae natoque dictum etiam semper magnis enim feugiat convallis convallis
							egestas rhoncus ridiculus in quis risus amet curabitur tempor orci penatibus.
							Tellus erat mauris ipsum fermentum etiam vivamus eget. Nunc nibh morbi quis 
							fusce hendrerit lacus ridiculus.</p>
						
							<div class="row">
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/A-million-suns-384369739" class="image full"><img src="images/pic02.jpg" alt="" /></a>
										<header>
											<h3>Ipsum Feugiat</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Mind-is-a-clear-stage-375431607" class="image full"><img src="images/pic03.jpg" alt="" /></a>
										<header>
											<h3>Rhoncus Semper</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/You-really-got-me-345249340" class="image full"><img src="images/pic04.jpg" alt="" /></a>
										<header>
											<h3>Magna Nullam</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Ad-infinitum-354203162" class="image full"><img src="images/pic05.jpg" alt="" /></a>
										<header>
											<h3>Natoque Vitae</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Elysium-355393900" class="image full"><img src="images/pic06.jpg" alt="" /></a>
										<header>
											<h3>Dolor Penatibus</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Emperor-of-the-Stars-370265193" class="image full"><img src="images/pic07.jpg" alt="" /></a>
										<header>
											<h3>Orci Convallis</h3>
										</header>
									</article>
								</div>
							</div>

						</div>
					</section>

				<!-- function -->
					<section id="function" class="two">
						<div class="container">
					
							<header>
								<h2>Portfolio</h2>
							</header>
							
							<p>Vitae natoque dictum etiam semper magnis enim feugiat convallis convallis
							egestas rhoncus ridiculus in quis risus amet curabitur tempor orci penatibus.
							Tellus erat mauris ipsum fermentum etiam vivamus eget. Nunc nibh morbi quis 
							fusce hendrerit lacus ridiculus.</p>
						
							<div class="row">
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/A-million-suns-384369739" class="image full"><img src="images/pic02.jpg" alt="" /></a>
										<header>
											<h3>Ipsum Feugiat</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Mind-is-a-clear-stage-375431607" class="image full"><img src="images/pic03.jpg" alt="" /></a>
										<header>
											<h3>Rhoncus Semper</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/You-really-got-me-345249340" class="image full"><img src="images/pic04.jpg" alt="" /></a>
										<header>
											<h3>Magna Nullam</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Ad-infinitum-354203162" class="image full"><img src="images/pic05.jpg" alt="" /></a>
										<header>
											<h3>Natoque Vitae</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Elysium-355393900" class="image full"><img src="images/pic06.jpg" alt="" /></a>
										<header>
											<h3>Dolor Penatibus</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Emperor-of-the-Stars-370265193" class="image full"><img src="images/pic07.jpg" alt="" /></a>
										<header>
											<h3>Orci Convallis</h3>
										</header>
									</article>
								</div>
							</div>

						</div>
					</section>

				<!-- Regex -->
					<section id="regex" class="two">
						<div class="container">
					
							<header>
								<h2>Portfolio</h2>
							</header>
							
							<p>Vitae natoque dictum etiam semper magnis enim feugiat convallis convallis
							egestas rhoncus ridiculus in quis risus amet curabitur tempor orci penatibus.
							Tellus erat mauris ipsum fermentum etiam vivamus eget. Nunc nibh morbi quis 
							fusce hendrerit lacus ridiculus.</p>
						
							<div class="row">
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/A-million-suns-384369739" class="image full"><img src="images/pic02.jpg" alt="" /></a>
										<header>
											<h3>Ipsum Feugiat</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Mind-is-a-clear-stage-375431607" class="image full"><img src="images/pic03.jpg" alt="" /></a>
										<header>
											<h3>Rhoncus Semper</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/You-really-got-me-345249340" class="image full"><img src="images/pic04.jpg" alt="" /></a>
										<header>
											<h3>Magna Nullam</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Ad-infinitum-354203162" class="image full"><img src="images/pic05.jpg" alt="" /></a>
										<header>
											<h3>Natoque Vitae</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Elysium-355393900" class="image full"><img src="images/pic06.jpg" alt="" /></a>
										<header>
											<h3>Dolor Penatibus</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Emperor-of-the-Stars-370265193" class="image full"><img src="images/pic07.jpg" alt="" /></a>
										<header>
											<h3>Orci Convallis</h3>
										</header>
									</article>
								</div>
							</div>

						</div>
					</section>

				<!-- Word Dir -->
					<section id="wordDir" class="two">
						<div class="container">
					
							<header>
								<h2>Portfolio</h2>
							</header>
							
							<p>Vitae natoque dictum etiam semper magnis enim feugiat convallis convallis
							egestas rhoncus ridiculus in quis risus amet curabitur tempor orci penatibus.
							Tellus erat mauris ipsum fermentum etiam vivamus eget. Nunc nibh morbi quis 
							fusce hendrerit lacus ridiculus.</p>
						
							<div class="row">
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/A-million-suns-384369739" class="image full"><img src="images/pic02.jpg" alt="" /></a>
										<header>
											<h3>Ipsum Feugiat</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Mind-is-a-clear-stage-375431607" class="image full"><img src="images/pic03.jpg" alt="" /></a>
										<header>
											<h3>Rhoncus Semper</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/You-really-got-me-345249340" class="image full"><img src="images/pic04.jpg" alt="" /></a>
										<header>
											<h3>Magna Nullam</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Ad-infinitum-354203162" class="image full"><img src="images/pic05.jpg" alt="" /></a>
										<header>
											<h3>Natoque Vitae</h3>
										</header>
									</article>
								</div>
								<div class="4u">
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Elysium-355393900" class="image full"><img src="images/pic06.jpg" alt="" /></a>
										<header>
											<h3>Dolor Penatibus</h3>
										</header>
									</article>
									<article class="item">
										<a href="http://ineedchemicalx.deviantart.com/art/Emperor-of-the-Stars-370265193" class="image full"><img src="images/pic07.jpg" alt="" /></a>
										<header>
											<h3>Orci Convallis</h3>
										</header>
									</article>
								</div>
							</div>

						</div>
					</section>

				<!-- About RORI -->
					<section id="about" class="three">
						<div class="container">

							<header>
								<h2>About RORI</h2>
							</header>

							<img src="images/about.png" width="100%" alt="" />
							
							<p>RORI is a free, flexible, multi-platform chatterbot created in 2011. The chatterbot was totally redesigned in september 2012 and today we are at the version 2. More informations <a href="http://enconn.fr/rori.php">here</a> and the github page <a href="https://github.com/AmarOk1412/RORI">here</a>. The chatterbot is available on Linux and Android but you can compile on windows.</p>

						</div>
					</section>
			
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
