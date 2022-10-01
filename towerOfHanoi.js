<script>
// javascript recursive function to
// solve tower of hanoi puzzle
function towerOfHanoi(n, from_rod, to_rod, aux_rod)
{
		if (n == 0)
		{
			return;
		}
		towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
		document.write("Move disk " + n + " from rod " + from_rod +
		" to rod " + to_rod+"<br/>");
		towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
	}

	// Driver code
	var N = 3;
	
	// A, B and C are names of rods
	towerOfHanoi(N, 'A', 'C', 'B');

// This code is contributed by gauravrajput1
</script>
