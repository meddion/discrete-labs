<?php
include_once 'Convert.php';
include_once 'Evaluate.php';

if (isset($_POST['exp']) && !empty($_POST['exp'])) {
    $exp = $_POST['exp'];
    $results = [];
    $error = '';

    /* Reverse polish notation */
    $expressions['infix-to-postfix'] = Convert::infixToPostfix($exp);
    $expressions['postfix-to-infix'] = Convert::postfixToInfix(
            implode(',', $expressions['infix-to-postfix'])
    );
    /* Polish notation*/
    $expressions['infix-to-prefix'] = Convert::infixToPrefix($exp);
    $expressions['prefix-to-infix'] = Convert::prefixToInfix(
        implode(',', $expressions['infix-to-prefix'])
    );

    foreach ($expressions as $key => $expression) {
        $prefix = ucfirst($key).': ';
        if (is_array($expression))
            $results[] = $prefix.implode(' ', $expression);
        else
            $results[] = $prefix.$expression;
    }

    $results[] = 'Evaluation';
    try {
        $results[] = 'Postfix: '.Evaluate::postfix($expressions['infix-to-postfix']);
        $results[] = 'Prefix: '.Evaluate::prefix($expressions['infix-to-prefix']);
    } catch (Exception $e) {
        $error = $e->getMessage();
        $results[count($results) - 1] .= ' undefined.';
    }
}
?>
<!DOCTYPE html>
<html lang="uk">
<head>
    <title>Lab_8</title>
    <link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
<div class="wrapper">
    <div class="main">
        <p class="title">Type your expression below...</p>
        <form action="<?=$_SERVER['REQUEST_URI'];?>" method="post" id="main-form">
            <ul>
                <li class="input"><input type="text" name="exp" value="<?=@$_POST['exp'];?>"></li>
                <?php if (isset($results) && !empty($results)): ?>
                    <?php foreach ($results as $result): ?>
                        <li class="result"><?=$result;?></li>
                    <?php endforeach;?>
                <?php endif; ?>

                <?php if (isset($error) && !empty($error)): ?>
                    <li class="error"><?=$error;?></li>
                <?php endif;?>
                <li><button type="submit">Send</button></li>
            </ul>
        </form>
    </div>
</div>
</body>
</html>
