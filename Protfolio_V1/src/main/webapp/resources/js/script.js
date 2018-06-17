$(document).ready(function()
	{
		var section = $('#section li');
		
		function toggleAccordion() {
		  section.removeClass('active');
		  $(this).addClass('active');
		}
		
		section.on('mouseover', toggleAccordion);
		//section.hover(toggleAccordion);
	}
);
/*
function onLoadPage(url){
		$("body").fadeOut(100, function(){
			console.log("fadeOut");
			window.location.href = url;
		})
	}*/

