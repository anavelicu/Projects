Satellites.cpp
~~~~~~~~~~~
	Implementation idea:
	
     - I opened the file and I stored the values for the number of satellites and the number of rockets. 
The weight of each rock is stored int the satellites vector.
     - The core of the program consists of the function minimal_payload. This function receives the vector with the 
weights of each satellite as a parameter, the number of rockets and the number of satellites. 
     - First, it computes two separate variables, a minimum (when we put each satelitte in its own rocket, as the minimal maximum payload of the rocket would be the maximum weight in the sattelite vector) and a maximum (when we put all the satellites in one rocket as the maximum payload of the rocket would be the sum of all weights in the sattelites vector) of possible payloads for the rockets.
     - Secondly, I apply the binary search algorith in order to find the optimal payload. By computing the mid between the
minimum and the maximum of possible payloads, I check using the function check_nr_loaded_rockets* if the rockets are "out of stock" or not. If the rockets are all used, it the maximum will take the value of the mid payload. Otherwise, the minimum will become the mid payload plus one. In such way, the minimal maximum payload of the rocket will be computed.
      - check_nr_loaded_rockets* - It receives the vector with the weights of the satellites, the number of satellites, the number of rockets and the payload (in our case, the mid payload which is calculated each time in the binary search). It computes the sum of all the weights (tmp_payload) and at each satellite it checks if tmp_payload is greater than the payload transmited as parameter. If so, tmp_payload takes the value of the weight of the current sattelite and we get to the next rocket. Then I check if I have in stock rockets. If not, it returs false.

	Complexity:

      - The complexity for the binary search is log(n), so because I have it in a for instruction, the complexity of the program will be :
	O(n*log(n))




Ice.cpp
~~~~~~
	Implementation idea:
	
     - In main I read and stored the input from the ice.in file. I computed the best time using the function optimal_equip.
     - The function optimal_equip computes the best time based on dynamic programming, which means I computed all the possible solutions based on the previous ones (~one step ahead thinking).
     - The specific details of the implementation are present in the comments in the code. 
     - The main difficulties encoutered occured trying to exclude, in the most optimal way, the intermediarry solutions that were no longer needed.
  
	Complexity:

     - Because I have a for and a while iterations in a for iteration, the complexity would be:
					n*(n+n) = n*2n  => O(n^2)