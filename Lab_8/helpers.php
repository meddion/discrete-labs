<?php
// Debug function
function debug($str = null, $die = true) {
    print '<pre>';
    var_dump($str);
    print '</pre>';
    if ($die) die();
}

function isNumber($value)
{
    return is_numeric($value) || ctype_alpha($value);
}

function isOperator($operator)
{
    return in_array($operator, [
        '-', '+', '*', '/', '^',
    ]);
}

function priority($char) {
    if ($char == '^')
        return 2;
    else if ($char == '*' || $char == '/')
        return 1;
    else if ($char == '+' || $char == '-')
        return 0;

    return -1;
}