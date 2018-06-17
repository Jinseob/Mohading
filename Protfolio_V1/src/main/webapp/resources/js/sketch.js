var canvas;
var x = 100,
y = 100,
angle1 = 0.0,
segLength = 50;

function windowResized() {
	console.log('resized');
	$(window).height();
	$("#menu").css("height", function(){
		console.log(windowHeight);
		return (windowHeight - 166) + "px";
	});
	
	resizeCanvas(windowWidth,windowHeight);
}

function setup() {
	canvas = createCanvas(windowWidth,windowHeight);
	canvas.position(0,0);
	canvas.style('z-index','-1');
}

function draw() {
background(256);

dx = mouseX - x;
dy = mouseY - y;
angle1 = atan2(dy, dx);
x = mouseX - (cos(angle1) * segLength);
y = mouseY - (sin(angle1) * segLength);

segment(x, y, angle1);
ellipse(x, y, 20, 20);
}

function segment(x, y, a) {
push();
translate(x, y);
rotate(a);
line(0, 0, segLength, 0);
pop();
}




