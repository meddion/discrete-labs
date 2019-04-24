<?php
include_once 'helpers.php';

class Evaluate
{
    public static function perform($token, $v1, $v2) {
        switch ($token) {
            case '+' : return $v1 + $v2;
            case '-' : return $v1 - $v2;
            case '*' : return $v1 * $v2;
            case '/' : return $v1 / $v2;
            case '^' : return pow($v1, $v2);
            default  : throw new Exception("Token '{$token}' is undefined.");
        }
    }

    public static function postfix(array $exp, array $arg = [])
    {
        $stack = [];
        foreach ($exp as $token) {
            if (isOperator($token)) {
                $operand2 = self::devoteConstant(array_pop($stack), $arg);
                $operand1 = self::devoteConstant(array_pop($stack), $arg);
                array_push(
                    $stack,
                    Evaluate::perform($token, $operand1, $operand2)
                );
            } else {
                array_push($stack, $token);
            }
        }
        return array_pop($stack);
    }

    public static function prefix(array $exp, array $arg = [])
    {
        $stack = [];
        for ($i = count($exp) - 1; $i >= 0; $i--) {
            if (isOperator($exp[$i])) {
                $operand1 = self::devoteConstant(array_pop($stack), $arg);
                $operand2 = self::devoteConstant(array_pop($stack), $arg);
                array_push(
                    $stack,
                    Evaluate::perform($exp[$i], $operand1, $operand2)
                );
            } else {
                array_push($stack, $exp[$i]);
            }
        }
        return array_pop($stack);
    }

    public static function devoteConstant($operand, array &$arg)
    {
        if (!is_numeric($operand)) {
            if (!isset($arg[$operand]) || !is_numeric($arg[$operand]))
                throw new Exception("Couldn't read a property '{$operand}'"
                ." in order to evaluate the expresion.");

            $operand = $arg[$operand];
        }
        return (float)$operand;
    }
}