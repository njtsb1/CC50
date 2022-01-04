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
    <title>CC50 Finance: Selling Stocks</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<nav>
		<a href="buy.php" title="Buy shares">Purchase</a><a href="sell.php" title="Sell shares">Sell</a>
		<a href="history.php" title="Transaction history">History</a><a href="quote.php" title="Consult share value">Cotações</a>
		<a href="password.php" title="Change your password">Change Password</a><a href="logout.php" title="Log off">To go out</a>
	</nav>

	<div id="middle">
		<?
 			$query1 = mysqli_query($connection, "SELECT username, cash FROM users WHERE uid = {$_SESSION["uid"]}");
 			$uc = mysqli_fetch_array($query1);
 			print("<table><tr><td>{$uc[0]}</td><td>Valor disponível: {$uc[1]}.</td></tr></table><br/>");
 			$query2 = mysqli_query($connection, "SELECT symbol, shares FROM wallet WHERE uid = {$_SESSION["uid"]}");
 			print("<table><tr><td>Nome</td><td>Symbol</td><td>Preço</td><td>+Baixo</td><td>+Alto</td><td>Quantidade</td></tr>");
 			while ($row = mysqli_fetch_array($query2)) {
 				$s = lookup($row["symbol"]);
 				print("<tr><td>{$s->name}</td><td>{$s->symbol}</td><td>{$s->price}</td><td>{$s->low}</td><td>{$s->high}</td>
 					   <td>{$row["shares"]}</td></tr>");
 			}
 			print("</table>");
 		?>
		<p>Sell shares</p>
 		<form action="sell2.php" method="post">
 			Symbol: <input type="text" name="ssym"/><br/>
 			The amount: <input type="number" name="ssha"><br/>
 			<input type="submit" value="Vender"/>
 		</form>
 	</div>

	<div id="bottom">
		<span>© njtsb1</span>
	</div>
</body>
</html>
