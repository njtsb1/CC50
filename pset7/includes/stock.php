<?php
	// Stock.php	CC50	Pset7	Defines a class (ie structure) for an action.

	class Stock
	{
		// action name

		public $name = NULL;

		// action symbol
		public $symbol = NULL;

        // latest share price
        public $price = NULL;

		// download of the most recent day
		public $low = NULL;

		// most recent day high
		public $high = NULL;

		/*
		// time at which the stock last changed hands (measured in the number
		// of seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)
		public $time = NULL;

		// percent by which the stock's price changed over the course 
		// of the most recent (business) day 
		public $change = NULL;

		// most recent (business) day's opening price
		public $open = NULL;
		*/
	}
?>
