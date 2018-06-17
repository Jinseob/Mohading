<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page session="false"%>

<!DOCTYPE html>
<html lang="en">

<head>
<title>Scrolling Nav - Start Bootstrap Template</title>

<!-- Bootstrap core CSS -->
<link href="/resources/vendor/bootstrap/css/bootstrap.min.css"
	rel="stylesheet">
<!-- Custom styles for this template -->
<link href="/resources/css/project.css" rel="stylesheet">
<link href="/resources/css/font/font.css" rel="stylesheet">

<!-- Bootstrap core JavaScript -->
<script src="/resources/vendor/jquery/jquery.min.js"></script>
<script src="/resources/vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

<!-- Plug-in JavaScript -->
<script src="/resources/vendor/jquery-easing/jquery.easing.min.js"></script>

<!-- Custom JavaScript for this theme -->
<script src="/resources/js/project.js"></script>

</head>
<body  data-spy="scroll" data-target="#mainNav" data-offset="20" class="scrollspy">

<div class="wrapper">
  <div class="row">
    <div class="contents">
      <div id="section1">    
        <h1>Project 3</h1>
        <p>Try to scroll this section and look at the navigation list while scrolling!</p>
      </div>
      <div id="section2"> 
        <h1>Project 2</h1>
        <p>Try to scroll this section and look at the navigation list while scrolling!</p>
      </div>        
      <div id="section3">         
        <h1>Project 1</h1>
        <p>Try to scroll this section and look at the navigation list while scrolling!</p>
      </div>
    </div>
    <nav class="navbar" id="mainNav">
      <ul class="nav flex-column">
        <li class="nav-item"><a href="#section1" class="nav-link">Project 3</a></li>
        <li class="nav-item"><a href="#section2" class="nav-link">Section 2</a></li>
        <li class="nav-item"><a href="#section3" class="nav-link">Section 3</a></li>
      </ul>
    </nav>
    <div class="outer">
	  <div class="inner">
	    <a href="/"><label>Back</label></a>
	  </div>
	</div>
  </div>
</div>
</body>

</html>