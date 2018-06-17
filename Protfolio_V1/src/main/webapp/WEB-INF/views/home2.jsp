<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page session="false" %>



<!doctype html>
<html lang="en">
 <head>
    <title>Seungmin Leee</title>

	<!-- Bootstrap core CSS -->
	<link href="/resources/vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">
	<!-- Custom styles for this template -->
	<link rel="stylesheet" href="/resources/css/style.css" type="text/css">
	 
	 
	<!-- Bootstrap core JavaScript -->   
    <script src="/resources/vendor/jquery/jquery.min.js"></script>
    <script src="/resources/vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
	<!-- Plug-in JavaScript -->	
   	<script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/0.5.16/p5.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/0.5.16/addons/p5.dom.js"></script>
   	<script src="/resources/vendor/jquery-easing/jquery.easing.min.js"></script>
   	<script src="/resources/vendor/jquery-smoothstate/jquery.smoothState.min.js"></script>
   	<script src="/resources/vendor/prefixfree/prefixfree.min.js"></script>
   	   	<!-- Custom JavaScript for this theme -->
    <script src="/resources/js/script.js" type="text/javascript"></script>
   	<script src="/resources/js/sketch.js" type="text/javascript"></script>
   	
   	<!-- Init -->
   	<script type="text/javascript">
   		$(document).ready(function(){
   			$("#menu").css("height", function(){
   				var winHeight = $(window).height();
   				console.log(winHeight);
   				return (winHeight - 166) + "px";
   			});
   		});
   	</script>
   	
  </head>
  <body>
	  <div id='main' class='m-scene'>
	  	<nav role="navigation">
		  <div id="menuToggle">
		    <input type="checkbox" />
		    
		    <span></span>
		    <span></span>
		    <span></span>
		    
		    <ul id="menu">   
		    </ul>
		  </div>
		</nav>

		<div class='scene-element scene-element--fadeInStretch'>
			<ul id="section">
			  <li class="active">
			    <div class="section-title">
			      <a href="#">Hello!</a>
			    </div>
			    <div class="section-content">
			      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Suscipit voluptatum temporibus dicta reprehenderit tempore quisquam consequuntur porro omnis laboriosam praesentium at et sapiente, provident sit! Suscipit recusandae, ab ratione dignissimos.</p>
			    </div>
			  </li>
			  <li>
			    <div class="section-title">
			      <a href="#">Projects</a>
			    </div>
			    <div class="section-content">
			      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Tempora totam delectus, eius nostrum aspernatur voluptas enim fugit ipsa magni voluptatem, odio sit accusamus vel id, commodi consequuntur possimus repellat necessitatibus!</p>
			    </div>
			  </li>
			  <li>
			    <div class="section-title">
			      <a href="./Link/experiments.do">Experiments</a>
			    </div>
			    <div class="section-content">
			      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Pariatur saepe vel facilis quae nihil ad aspernatur ex delectus. Tenetur nulla voluptates similique quos, quia possimus, magnam esse natus quis ipsa.</p>
			    </div>
			  </li>
			  <li>
			    <div class="section-title">
			      <a href="./Link/artwork.do">Artwork</a>
			    </div>
			    <div class="section-content">
			      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Adipisci, optio illo, delectus deleniti animi accusamus. Laboriosam maiores totam provident aliquam. Unde, incidunt amet officia a obcaecati, ducimus at molestiae nemo.</p>
			    </div>    
			  </li>
			</ul>
		</div>
	</div>
  </body>
</html>