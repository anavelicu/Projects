<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Grocery list</title>
  <link href="https://fonts.googleapis.com/css2?family=Source+Sans+Pro:ital,wght@1,700&display=swap" rel="stylesheet">
  <link href="https://fonts.googleapis.com/css2?family=Anton&display=swap" rel="stylesheet">
  <link href="https://fonts.googleapis.com/css2?family=Quicksand:wght@700&display=swap" rel="stylesheet">
	<link rel="stylesheet" href="css/stylegrocery.css">
  <link rel="stylesheet" href="css/styleheader.css">
  <link rel="stylesheet" href="css/bootstrap.css">

</head>
<body>
  <?php
  include 'inc/header.php';
  ?>
    <div class = "container">
       <div class = "left">
          <div class = "row">
           <div class = "col-md-12">
              <h1>Build your own grocery list</h1>
            </div>
          </div>

          <div class="row">
            <div class="col-md-12">
              <div class = "text">
                <p style ="text-indent: 50px;">In case you did not know, food plays a big role in your diet. We live busy lives, shuttling back and forth between home, jobs, social events, and many other commitments. At times, we feel there is no time to exercise, or we have no choice but to grab the convenient food over the healthy food.</p>
                <p style="text-indent: 50px;">Many people tend to flip the equation, prioritizing fitness over food. We use our exercise as an excuse to eat whatever we want, and burn the calories off later. While the plan isn’t bad, it’s very short-sighted. A healthy diet combined with regular exercise is clearly the best way to live, instead of constantly trying to burn off the donuts you ate.</p>
                <p style="text-indent: 50px;">Having a shopping list is a great way to only buy the foods that your body really needs. We have already added some products we think are important for you in order to get started.</p>

              </div>
            </div>
          </div>

          <div class = "row">
            <div class = "col-md-12">
              <a href="list.php"><button class="btnstart">Start</button></a>
            </div>
          </div>
        </div>
    </div>
</body>
</html>