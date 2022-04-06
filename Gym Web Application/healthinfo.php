<!DOCTYPE html>
<html>
<head>
	<title>Health Info</title>
	<link rel="stylesheet" href="css/stylehealth.css">
	<link rel="stylesheet" href="css/styleheader.css">
	<link rel="stylesheet" href="css/bootstrap.css">
	<link href="https://fonts.googleapis.com/css2?family=Source+Sans+Pro:ital,wght@1,700&display=swap" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css2?family=Heebo:wght@800&display=swap" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css2?family=Barlow:wght@200&display=swap" rel="stylesheet">
</head>
<body>	
  <?php
  include 'inc/header.php';
  ?>
  
	<div class = "center">
		<div class="container">
			<div class = "row">
				<div class = "col-md-12">
					<div id="displayTopic">Sleep</div>
					 <div id="displayInfo">Sleep gives your body time to recover, conserve energy, and repair and build up the muscles worked during exercise. When we get enough good quality sleep, the body produces growth hormone. During childhood and adolescence, growth hormone makes us grow. And when we are older, it helps us build lean muscle and helps our body repair when we have torn ourselves up during a hard workout.Growth hormone is essential for athletic recovery.</div>
				</div>
			</div>
			<div class = "row">
				<div class = "col-md-3">
					<button id="btnNext">Next</button>
				</div>
			</div>
			<script>
				 let topic = document.getElementById("topic"),
					 displayInfo = document.getElementById("displayInfo"),
					 btnNext = document.getElementById("btnNext");
					 var topics = ["Stress", "Food"];
					 let count = 0;

					 function changeTopic(){
					 	if(count >= topics.length)
					 	{
					 		displayTopic.innerHTML = "We will add more of this soon";
					 		displayInfo.innerHTML = "";
					 	}
					 	else{
					 	displayTopic.innerHTML = topics[count];
					 	if(topics[count] === "Stress")
					 	{
					 		displayInfo.innerHTML = "Exercise can be an effective component of a stress management program, and all types of exercise can be beneficial for stress. Exercising after a long day can be a great way to blow off steam and clear your head. But starting a high-intensity workout when you’re feeling super stressed can actually undermine your efforts. Stress is a serious de-motivator so be careful not to let it overwhelm you!";
					 	}
					 	if(topics[count] === "Food")
					 	{
					 		displayInfo.innerHTML = "Eating a well-balanced diet can help you get the calories and nutrients you need to fuel your daily activities, including regular exercise. When it comes to eating foods to fuel your exercise performance, it’s not as simple as choosing vegetables over doughnuts. You need to eat the right types of food at the right times of the day.Learn about the importance of healthy breakfasts, workout snacks, and meal plans.";
					 	}
					 	count++;
						}
					 }

					 btnNext.addEventListener('click', changeTopic);
			</script>
		</div>
	</div>

</body>
</html>