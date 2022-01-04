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
    <title>CC50 Finance: Change Password</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finance" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<nav>
		<a href="buy.php" title="Buy shares">Purchase</a><a href="sell.php" title="Sell shares">Sell</a>
		<a href="history.php" title="Transaction history">History</a><a href="quote.php" title="Consult share value">Quotation</a>
		<a href="password.php" title="Change your password">Change Password</a><a href="logout.php" title="Log off">To go out</a>
	</nav>

	<div id="middle">
		<form action="password2.php" method="post">
			Old Password: <input type="password" name="pass1"/><br/>
			New Password: <input type="password" name="pass2"/><br/>
			Repeat new password: <input type="password" name="pass3"/><br/>
			<input type="submit" value="To exchange"/>
		</form>
	</div>

	<div id="bottom">
		<span>© njtsb1</span>
	</div>
</body>
</html>
