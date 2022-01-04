<?php
	require_once("includes/common.php");
	$s = lookup($_POST["symbol"]);
	if (!$s)
		apologize("Invalid Symbol.");
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
	<title>CC50 Finance: Quotation Value</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finance" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<div id="middle">
		<p><div style="text-align: center">The action <?= $s->name ?> currently costs $<?= $s->price ?>.</div></p>
		<p><a href="javascript:history.go(-1);">Return</a></p>
	</div>

	<div id="bottom">
		<span>© njtsb1</span>
	</div>
</body>
</html>
