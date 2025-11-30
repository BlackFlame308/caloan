<!DOCTYPE html>
<html>
<head>
    <title>Loan Calculator with Amortization</title>
    <style>
        body {
            font-family: Arial;
            background: #f0f0f0;
            padding: 20px;
        }

        form {
            background: white;
            padding: 20px;
            width: 350px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }

        input {
            width: 100%;
            padding: 8px;
            margin: 8px 0;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
            background: white;
        }

        table, th, td {
            border: 1px solid #aaa;
        }

        th, td {
            padding: 8px;
            text-align: center;
        }

        .header {
            font-size: 22px;
            margin-bottom: 20px;
        }

        @media print {
            body * {
                visibility: hidden;
            }
            #printArea, #printArea * {
                visibility: visible;
            }
            #printArea {
                position: absolute;
                left: 0;
                top: 0;
                width: 100%;
            }
        }
    </style>
</head>
<body>

<h2 class="header">Loan Calculator with Amortization</h2>

<form method="POST">
    <label>Username:</label>
    <input type="text" name="username" required>

    <label>Loan Amount:</label>
    <input type="number" name="amount" step="0.01" required>

    <label>Interest Rate (Annual %):</label>
    <input type="number" name="interest" step="0.01" required>

    <label>Months of Payment:</label>
    <input type="number" name="months" required>

    <input type="submit" name="calculate" value="Calculate">
</form>

<?php
if (isset($_POST['calculate'])) {

    $username = $_POST['username'];
    $amount = $_POST['amount'];
    $annual_interest = $_POST['interest'];
    $months = $_POST['months'];

    // Convert annual interest to monthly
    $monthly_interest = ($annual_interest / 100) / 12;

    // Monthly amortization formula
    $monthly_payment = $amount * 
        ( $monthly_interest * pow(1 + $monthly_interest, $months) ) /
        ( pow(1 + $monthly_interest, $months) - 1 );

    echo "<h3>Hello, $username!</h3>";
    echo "<h3>Loan Amount: ₱" . number_format($amount, 2) . "</h3>";  // <-- ADDED LINE
    echo "<h3>Monthly Payment: ₱" . number_format($monthly_payment, 2) . "</h3>";

    echo "<button onclick='window.print()' 
            style='padding:10px 20px; margin-top:10px; cursor:pointer;'>Print Amortization Table</button><br><br>";

    echo "<div id='printArea'>";
    echo "<h2>Amortization Table for $username</h2>";
    echo "<table>";
    echo "<tr>
            <th>Month</th>
            <th>Payment</th>
            <th>Interest</th>
            <th>Principal</th>
            <th>Remaining Balance</th>
          </tr>";

    $balance = $amount;

    for ($i = 1; $i <= $months; $i++) {
        $interest_payment = $balance * $monthly_interest;
        $principal_payment = $monthly_payment - $interest_payment;
        $balance -= $principal_payment;

        echo "<tr>";
        echo "<td>$i</td>";
        echo "<td>" . number_format($monthly_payment, 2) . "</td>";
        echo "<td>" . number_format($interest_payment, 2) . "</td>";
        echo "<td>" . number_format($principal_payment, 2) . "</td>";
        echo "<td>" . number_format(max($balance, 0), 2) . "</td>";
        echo "</tr>";
    }

    echo "</table>";
    echo "</div>";
}
?>

</body>
</html>
