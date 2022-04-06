<?php
		$q1 = "";
		$q2 = "";
		$q3 = "";
		$q4 = "";
		$q5 = "";

		$sum = 0;
		if(isset($_POST['q1']) && isset($_POST['q2']) && isset($_POST['q3']) && isset($_POST['q4']) && isset($_POST['q5']))
		{
			 $q1 = $_POST['q1'];
			 $q2 = $_POST['q2'];
			 $q3 = $_POST['q3'];
			 $q4 = $_POST['q4'];
			 $q5 = $_POST['q5'];
		}

		if($q1 == "a1")
		  {
		  	$sum += 1;
		  }
		 if($q1 == "a2")
		  {
		  	$sum += 2;
		  }	  

		 if($q1 == "a3")
		  {
		  	$sum += 3;
		  }

		if($q2 == "a1")
		  {
		  	$sum += 1;
		  }
		 if($q2 == "a2")
		  {
		  	$sum += 2;
		  }	  

		 if($q2 == "a3")
		  {
		  	$sum += 3;
		  }

		if($q3 == "a1")
		  {
		  	$sum += 1;
		  }
		 if($q3 == "a2")
		  {
		  	$sum += 2;
		  }	  

		 if($q3 == "a3")
		  {
		  	$sum += 3;
		  }

		if($q4 == "a1")
		  {
		  	$sum += 1;
		  }
		 if($q4 == "a2")
		  {
		  	$sum += 2;
		  }	  

		 if($q4 == "a3")
		  {
		  	$sum += 3;
		  }

		if($q5 == "a1")
		  {
		  	$sum += 1;
		  }
		 if($q5 == "a2")
		  {
		  	$sum += 2;
		  }	  

		 if($q5 == "a3")
		  {
		  	$sum += 3;
		  }	
?>
		