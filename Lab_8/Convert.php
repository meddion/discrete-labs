<?php
include_once 'helpers.php';

class Convert
{
    public static function infixToPostfix($exp)
    {
        $exp = self::sanitize($exp);
        $output = [];
        $stack = [];
        $len = strlen($exp);

        for ($i = 0; $i < $len; $i++) {
            if (isNumber($exp[$i])) {
                $num = '';
                do {
                    $num .= $exp[$i];
                    $i++;
                } while ($i < $len && isNumber($exp[$i]));
                if (!empty($num)) array_push($output, $num);
                $i--;
            } else if (isOperator($exp[$i])) {
                while (!empty($stack) && priority($exp[$i]) <= priority(end($stack)))
                    array_push($output, array_pop($stack));
                array_push($stack, $exp[$i]);
            } else if ($exp[$i] == '(') {
                array_push($stack, '(');
            } else if ($exp[$i] == ')') {
                while (!empty($stack) && ($operator = array_pop($stack)) !== '(')
                    array_push($output, $operator);
            }
        }

        while (!empty($stack))
            array_push($output, array_pop($stack));

        return $output;
    }

    public static function postfixToInfix($exp) {
        $exp = self::sanitize($exp);
        $stack = [];
        $len = strlen($exp);

        for ($i = 0; $i < $len; $i++) {
            if (isNumber($exp[$i])) {
                $num = '';
                do {
                    $num .= $exp[$i];
                    $i++;
                } while ($i < $len && isNumber($exp[$i]));
                if (!empty($num)) array_push($stack, $num);
                $i--;
            } else if (isOperator($exp[$i])) {
                $operator2 = array_pop($stack);
                $operator1 = array_pop($stack);
                array_push($stack, '('.$operator1.' '.$exp[$i].' '.$operator2.')');
            }
        }
        return self::trimExp($stack[0]);
    }

    public static function infixToPrefix($exp)
    {
        $exp = self::sanitize($exp);
        $output = [];
        $stack = [];
        $len = strlen($exp);

        for ($i = 0; $i < $len; $i++) {
            if (isNumber($exp[$i])) {
                $num = '';
                do {
                    $num .= $exp[$i];
                    $i++;
                } while ($i < $len && isNumber($exp[$i]));
                if (!empty($num)) array_push($output, $num);
                $i--;
            } else if (isOperator($exp[$i])) {
                while (!empty($stack) && priority($exp[$i]) <= priority(end($stack))) {
                    $operand1 = array_pop($output);
                    $operand2 = array_pop($output);
                    $operator = array_pop($stack);
                    array_push($output, $operator.' '.$operand2.' '.$operand1);
                }
                array_push($stack, $exp[$i]);
            } else if ($exp[$i] == '(') {
                array_push($stack, '(');
            } else if ($exp[$i] == ')') {
                while (!empty($stack) && ($operator = array_pop($stack)) !== '(') {
                    $operand1 = array_pop($output);
                    $operand2 = array_pop($output);
                    array_push($output, $operator.' '.$operand2.' '.$operand1);
                }
            }
        }

        while (!empty($stack)) {
            $operand1 = array_pop($output);
            $operand2 = array_pop($output);
            $operator = array_pop($stack);
            array_push($output, $operator.' '.$operand2.' '.$operand1);
        }

        return explode(' ', array_pop($output));
    }

    public static function prefixToInfix($exp) {
        $exp = self::sanitize($exp);
        $stack = [];
        $len = strlen($exp);

        for ($i = $len - 1; $i >= 0; $i--) {
            if (isNumber($exp[$i])) {
                $num = '';
                do {
                    $num .= $exp[$i];
                    $i--;
                } while ($i >= 0 && isNumber($exp[$i]));
                if (!empty($num)) array_push($stack, strrev($num));
                $i++;
            } else if (isOperator($exp[$i])) {
                $operator1 = array_pop($stack);
                $operator2 = array_pop($stack);
                array_push($stack, '('.$operator1.' '.$exp[$i].' '.$operator2.')');
            }
        }
        return self::trimExp($stack[0]);
    }

    public static function trimExp($exp)
    {
        if (substr($exp, 0, 1) == '(' && substr($exp, -1) == ')')
            return substr($exp, 1, -1);

        return $exp;
    }

    public static function sanitize($exp)
    {
        return trim(str_replace(' ', '', $exp));
    }
}