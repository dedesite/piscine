$(function(){
	var canvas = $("#board").get(0);
	var ctx = canvas.getContext("2d");
	var firstClick = true;
	var drawPos = [{x:0, y:0}, {x:0, y:0}];
	var option = null;
	var drawing = false;
	
	ctx.strokeRect(0, 0, 300, 300);

	$("#color").click(function(e){
		if(e.target.id !== "color")
			ctx.strokeStyle = e.target.id;
	});

	$("#toolbar").click(function(e){
		if(e.target.id !== "toolbar")
		{
			option = e.target.id;
			firstClick = true;
			ctx.closePath();
		}
	});

	$("#board").click(function(e){
		var ind = firstClick ? 0 : 1;
		drawPos[ind] = getMousePos(e);
		if(!firstClick)
			drawShape(option);
		firstClick = !firstClick;
	});

	$("#board").mousedown(function(e){
		if(option === "pencil"){
			var pos = getMousePos(e);
			ctx.beginPath();
			ctx.moveTo(pos.x, pos.y);
			drawing = true;
		}
	});

	$("#board").mousemove(function(e){
		if(option === "pencil" && drawing === true){
			var pos = getMousePos(e);
			ctx.lineTo(pos.x, pos.y);
			ctx.stroke();
		}
	});

	$("#board").mouseup(function(e){
		stopDrawing();
	});

	$("body").mouseup(function(e){
		stopDrawing();
	});

	function stopDrawing()
	{
		if(option === "pencil"){
			drawing = false;
			ctx.closePath();
		}		
	}

	function getMousePos(e){
		return {x:e.pageX - canvas.offsetLeft, y:e.pageY - canvas.offsetTop};
	}	

	function drawShape(shape)
	{
		if(shape === "rectangle"){
			ctx.strokeRect(drawPos[0].x, drawPos[0].y, 
				drawPos[1].x - drawPos[0].x, drawPos[1].y - drawPos[0].y);
		}
		else if(shape === "circle"){
			ctx.beginPath();
			var radius = Math.abs(drawPos[1].x - drawPos[0].x);
			ctx.arc(drawPos[0].x, drawPos[0].y, radius,0, Math.PI*2,true);
			ctx.stroke();
			ctx.closePath();
		}
		else if(shape === "line"){
			ctx.beginPath();
			ctx.moveTo(drawPos[0].x, drawPos[0].y);
			ctx.lineTo(drawPos[1].x, drawPos[1].y);
			ctx.stroke();
			ctx.closePath();
		}
	}
});