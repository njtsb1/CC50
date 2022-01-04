<?php
	// require common code
	require_once("includes/common.php");

	$symbol = mysqli_real_escape_string($connection, $_POST["ssym"]);
	$shares = mysqli_real_escape_string($connection, $_POST["ssha"]);

	if (!preg_match("/^\d+$/", $shares))
		apologize("You can only buy with positive integer values.");

	$stock = lookup($symbol);
	$query = mysqli_query($connection, "SELECT cash FROM users WHERE uid = {$_SESSION["uid"]}");
	$slices = mysqli_fetch_array($query);

	if ($shares > $slices["cash"])
		apologize("You don't have enough money to buy.");

	if (!mysqli_query($connection, "INSERT INTO wallet (uid, symbol, shares) VALUES ({$_SESSION["uid"]}, '$stock->symbol', $shares)
									ON DUPLICATE KEY UPDATE shares = shares + $shares"))
		apologize("Failed to buy the share \"{$stock->name}\".");

	if (!mysqli_query($connection, "UPDATE users SET cash = cash - $stock->price WHERE uid = {$_SESSION["uid"]}"))
		apologize("Failed to remove money from your wallet.");

	if (!mysqli_query($connection, "INSERT INTO history (uid, operation, symbol, stocks, price)
									VALUES ({$_SESSION["uid"]}, 'B', '$stock->symbol', $shares, $stock->price)"))
		apologize("Failed to store information in history.");

	redirect("buy.php");
?>
