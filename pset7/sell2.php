<?php
	// require common code
	require_once("includes/common.php");

	$symbol = mysqli_real_escape_string($connection, $_POST["ssym"]);
	$shares = mysqli_real_escape_string($connection, $_POST["ssha"]);
	$stock = lookup($symbol);
	$query = mysqli_query($connection, "SELECT shares FROM wallet WHERE uid = {$_SESSION["uid"]} AND symbol = '{$symbol}'");
	$slices = mysqli_fetch_array($query);

	if (empty($slices))
		apologize("You have no shares \"{$symbol}\".");

	if ($shares > $slices["shares"])
		apologize("You can't sell more than what you have.");

	if (!mysqli_query($connection, "UPDATE wallet SET shares = shares - {$shares} WHERE uid = {$_SESSION["uid"]} AND symbol = '{$symbol}'"))
		apologize("Failed to sell the share \"{$stock->name}\".");

	if (!mysqli_query($connection, "UPDATE users SET cash = cash + {$stock->price} WHERE uid = {$_SESSION["uid"]}"))
		apologize("Failed to add money to your wallet.");

	if (!mysqli_query($connection, "INSERT INTO history (uid, operation, symbol, stocks, price)
									VALUES ({$_SESSION["uid"]}, 'S', '{$stock->symbol}', {$shares}, {$stock->price})"))
		apologize("Failed to store information in history.");

	redirect("sell.php");
?>
