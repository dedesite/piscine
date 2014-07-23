var DOM_VK_LEFT = 37;
var DOM_VK_UP = 38;
var DOM_VK_RIGHT = 39;
var DOM_VK_DOWN = 40;

var grid;

/**Return a random int between 0 and 3*/
function get_random_pos(){
	return Math.floor(Math.random() * 4);
}

/**Spawn a 2 (90%) or a 4 in a random position where there is still place*/
function spawn_number(){
	var line = get_random_pos();
	var col = get_random_pos();
	while(grid[line][col] != 0){
		line = get_random_pos();
		col = get_random_pos();
	}
	grid[line][col] = Math.random() < 0.9 ? 2 : 4;
}

function start(){
	grid = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];
	spawn_number();
	spawn_number();
}

/**
Move elements of a 4 length int tab to the right or the left 
and merge identical numbers by adding them 
*/
function merge_tab(tab, left){
	function move_tab(a, b){
		return left === true ? a === 0 : b === 0;
	}
	tab.sort(move_tab);
	//Check pairs
	for(var i = 0 ; i < 3 ; i++){
		if(tab[i] === tab[i+1]){
			if(left === true){
				tab[i] = tab[i] + tab[i + 1];
				tab[i + 1] = 0;
			}
			else{
				tab[i + 1] = tab[i] + tab[i + 1];
				tab[i] = 0;
			}
			i++;
		}
	}
	//Then move everything
	tab.sort(move_tab);
}

function inverse_grid(grid_to_inv){
	var g = [];
	for(var i = 0; i < 4; i++){
		g[i] = [];
		for(var j = 0; j < 4; j++){
			g[i][j] = grid_to_inv[j][i];
		}
	}
	return g;
}
/**
Move the entire grid
@attr direction : left, rigth, up, down
*/
function move_grid(direction){
	if(direction === "up" || direction === "down"){
		grid = inverse_grid(grid);
	}

	var left = direction === "left" || direction === "up";
	for(i = 0; i < 4; i++){
		merge_tab(grid[i], left);
	}

	if(direction === "up" || direction === "down"){
		grid = inverse_grid(grid);
	}
}

/**Simply display all the numbers in row of 4*/
function display_grid(){
	var grid_html = "";
	for(var i = 0; i < 4; i++){
		grid_html += grid[i].toString().replace(/0/g, "_").replace(/,/g, " ");
		grid_html += "<br>";
	}
	document.getElementById("grid").innerHTML = grid_html;
}

function is_grid_full(){
	grid_full = true;
	for(var i = 0 ; i < 4 ; i++){
		for(var j = 0; j < 4; j++){
			if(grid[i][j] == 0){
				grid_full = false;
				break;
			}
		}
	}
	return grid_full;
}

window.addEventListener("keydown", function (event) {
	if(is_grid_full()){
		document.getElementById("grid").innerHTML = "Game over";
		start();
	}
	var has_moved = true;
	switch(event.keyCode){
		case DOM_VK_UP:
			move_grid("up");
			break;
		case DOM_VK_DOWN:
			move_grid("down");
			break;
		case DOM_VK_LEFT:
			move_grid("left");
			break;
		case DOM_VK_RIGHT:
			move_grid("right");
			break;
		default:
			has_moved = false;
			break;
	}
	if(has_moved){
		spawn_number();
		display_grid();
	}
});

start();
display_grid();