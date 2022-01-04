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
    <title>CC50 Finance: Operations History</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finance" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<nav>
		<a href="buy.php" title="Buy shares">Purchase</a><a href="sell.php" title="Sell share">Sell</a>
		<a href="history.php" title="Transaction history">History</a><a href="quote.php" title="Consult share value">Quotation</a>
		<a href="password.php" title="Change your password">Change Password</a><a href="logout.php" title="Log off">To go out</a>
	</nav>

	<div id="middle">
		<?
			$query = mysqli_query($connection, "SELECT * FROM history WHERE uid = {$_SESSION["uid"]}");
			print("<table><tr><td>Action</td><td>Operation</td><td>The amount</td><td>Price</td><td>Date</td></tr>");
			while ($row = mysqli_fetch_array($query)) {
				$type = ($row["operation"] == "B") ? "Purchase" : "Sell";
				print("<tr><td>{$row["symbol"]}</td><td>$type</td><td>{$row["stocks"]}</td><td>{$row["price"]}</td>
					   <td>{$row["date"]}</td></tr>");
			}
			print("</table>");
		?>
	</div>
	<div id="bottom">
		<span>© njtsb1</span>
	</div>
</body>
</html>
