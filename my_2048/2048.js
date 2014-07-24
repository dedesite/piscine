var DIRECTIONS = {37:"left", 38:"up", 39:"right",40:"down"};

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
		return a === 0;
	}
	tab.sort(move_tab);
	if(left === false){
		tab.reverse();
	}
	//merge pairs
	for(var i = 0 ; i < tab.length - 1 ; i++){
		if(tab[i] === tab[i+1]){
			tab[i] = tab[i] + tab[i + 1];
			tab[i + 1] = 0;
			i++;
		}
	}
	//Then move everything
	tab.sort(move_tab);
	if(left === false){
		tab.reverse();
	}
}

function inverse_grid(grid_to_inv){
	var g = [];
	for(var i = 0; i < grid.length; i++){
		g[i] = [];
		for(var j = 0; j < grid[i].length; j++){
			g[i][j] = grid_to_inv[j][i];
		}
	}
	return g;
}
/**
Move the entire grid
@attr direction : left, right, up, down
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
	var grid_html = '<div class="grid">';
	for(var i = 0; i < grid.length; i++){
		for(var j = 0; j < grid[i].length; j++){
			if(grid[i][j] === 0){
				grid_html += '<div class="cell"></div>';	
			}
			else{
				grid_html += '<div class="cell">' + grid[i][j]+ '</div>';		
			}
		}
	}
	grid_html += '</div>';
	document.getElementById("grid").innerHTML = grid_html;
}

function is_grid_full(){
	grid_full = true;
	for(var i = 0 ; i < grid.length ; i++){
		if(grid[i].indexOf(0) !== -1){
			grid_full = false;
			break;
		}
	}
	return grid_full;
}

window.addEventListener("keydown", function (event) {
	var dir = DIRECTIONS[event.keyCode];
	if(is_grid_full()){
		document.getElementById("grid").innerHTML = "Game over";
		start();
	}

	if(dir != null){
		move_grid(dir);
		spawn_number();
		display_grid();
	}
});

start();
display_grid();