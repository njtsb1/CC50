<?php
	// require common code
	require_once("includes/common.php");
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
    <title>CC50 Finance: Buy Shares</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finance" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<nav>
		<a href="buy.php" title="Buy Shares">Purchase</a><a href="sell.php" title="Sell share">Sell</a>
		<a href="history.php" title="Transation history">History</a><a href="quote.php" title="Consult share value">Quotation</a>
		<a href="password.php" title="Change your password">Change password</a><a href="logout.php" title="Log off">To go out</a>
	</nav>

	<div id="middle">
		<?
			$query = mysqli_query($connection, "SELECT username, cash FROM users WHERE uid = {$_SESSION["uid"]}");
			$uc = mysqli_fetch_array($query);
			print("<table><tr><td>{$uc[0]}</td><td>Available value: {$uc[1]}.</td></tr></table>");
		?>
		<p>Buy Shares</p>
		<form action="buy2.php" method="post">
			Symbol: <input type="text" name="ssym"/><br/>			
			The amount: <input type="number" name="ssha"><br/>
			<input type="submit" value="Purchase"/>
		</form>
	</div>
	<div id="bottom">
		<span>© njtsb1</span>
	</div>
</body>
</html>
