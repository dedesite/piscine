let score = 0;

function getRandomPos() {
	return [0, 0].map(() => Math.floor(Math.random() * 4));
}

/**
 * Spawn a 2 (in 90% of the case) or a 4 in a random position where there is still place
 */
function spawnNumber(grid) {
	let x, y;
	do {
		[x, y] = getRandomPos();
	} while (grid[x][y] != 0)
	grid[x][y] = Math.random() < 0.9 ? 2 : 4;
	return grid;
}

/**
 * Fill the grid with 0 (no numbers), reset the score and spawn two numbers
 */
function start() {
	let grid = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];
	score = 0;
	grid = spawnNumber(grid);
	grid = spawnNumber(grid);
	return grid;
}

/**
 * IMHO best way to transpose a Matrix https://stackoverflow.com/a/36164530
 */
function transposeGrid(grid) {
	return grid[0].map((x, i) => grid.map(y => y[i]))
}

function reverseGrid(grid) {
	return grid.map(row => row.reverse())
}

/**
 * Merge a row to the left and update score if merged
 * Examples :
 * [2, 0, 0, 2] => [4, 0, 0, 0]
 * [2, 2, 0, 4] => [4, 4, 0, 0]
 * [0, 0, 0, 4] => [4, 0, 0, 0]
 * [0, 0, 2, 4] => [2, 4, 0, 0]
 * [2, 4, 2, 4] => [2, 4, 2, 4]
 */
function mergeEvenLeft2(row) {
	return row.map((num, index, row) => {
		const nextNumInd = row.findIndex((val, ind) => ind > index && val !== 0);

		if (nextNumInd !== -1 && row[nextNumInd] === num) {
				row[nextNumInd] = 0;
				score += num * 2;
				return num * 2;
		}
		return num;
	}).sort(a => a === 0);
}

/*
 * Alternativ version
 */
function mergeEvenLeft(row) {
	const removeZeros = arr => arr.filter(cell => cell !== 0);

	const mergedRow = removeZeros(row).reduce((mergedRow, currentCell, currentIndex, rowWithoutZeros) => {
		const prevCell = currentIndex > 0 && rowWithoutZeros[currentIndex - 1];
		const prevMergedCell = currentIndex > 0 && mergedRow[currentIndex - 1]
		const nextCell = currentIndex < 3 && rowWithoutZeros[currentIndex + 1];

		// If prevCell has been merged
		if (prevCell && prevMergedCell !== 0 && (prevCell !== prevMergedCell)) {
			mergedRow.push(0);
		} else if (currentCell === nextCell) {
			score += currentCell * 2;
			mergedRow.push(currentCell * 2);
		} else {
			mergedRow.push(currentCell);
		}
		return mergedRow;
	}, []);
	return removeZeros(mergedRow);
}

function moveLeft(row) {
	const mergedRow = mergeEvenLeft(row);
	return mergedRow.concat(Array(row.length - mergedRow.length).fill(0));
}
/**
 * Merge all rows to the left
 */
function moveGridLeft(grid) {
	return grid.map(moveLeft);
}

/**
 * Move the entire grid in a specific direction and merge number that are equals and side by side
 * @direction : left, right, up, down
*/
function moveGrid(grid, direction) {
	// In order to work with only rows, we transpose the grid on up and down moves.
	const transpose = ['up', 'down'].includes(direction);
	// Since the merge algo is only left oriented, we reverse the grid on right and down moves
	const reverse = ['right', 'down'].includes(direction);

	if (transpose) grid = transposeGrid(grid);
	if (reverse) grid = reverseGrid(grid);

	grid = moveGridLeft(grid);

	if (reverse) grid = reverseGrid(grid);
	if (transpose) grid = transposeGrid(grid);

	return grid;
}

/**
 * Simply display all the numbers in row of 4
 * And the current score
 */
function displayGrid(grid, score) {
	let grid_html = `<div class="score">Score : ${score}</div><div class="grid">`;

	grid.forEach(row => {
		row.forEach(num => {
			grid_html += `<div class="cell tile-${num}">${num || ''}</div>`;
		});
	});
	grid_html += '</div>';
	document.getElementById("grid").innerHTML = grid_html;
}

/**
 * @return true if there is no space left in the grid
 */
function isGridFull(grid) {
	return !grid.some(row => row.includes(0));
}

window.onload = function () {
	let grid;

	window.onkeydown = function (event) {
		const DIRECTIONS = {37:"left", 38:"up", 39:"right",40:"down"};
		const dir = DIRECTIONS[event.keyCode];

		if(isGridFull(grid)){
			document.getElementById("grid").innerHTML = "Game over";
			grid = start();
			score = 0;
		}

		if(dir != null){
			// Try to move the grid
			const gridBefore = JSON.stringify(grid);
			grid = moveGrid(grid, dir)
			if(JSON.stringify(grid) !== gridBefore){
				// If it has moved, then spawn a new number
				grid = spawnNumber(grid);
				// And refresh the grid
				displayGrid(grid, score);
			}
		}
	};

	grid = start();
	displayGrid(grid);
}

// console.log('[2, 0, 0, 2] => [4, 0, 0, 0]', mergeEvenLeft2([2, 0, 0, 2]));
// console.log('[2, 4, 2, 4] => [2, 4, 2, 4]', mergeEvenLeft2([2, 4, 2, 4]));
// console.log('[2, 2, 0, 4] => [4, 4, 0, 0]', mergeEvenLeft2([2, 2, 0, 4]));
// console.log('[0, 0, 0, 4] => [4, 0, 0, 0]', mergeEvenLeft2([0, 0, 0, 4]));
// console.log('[0, 0, 2, 4] => [2, 4, 0, 0]', mergeEvenLeft2([0, 0, 2, 4]));
