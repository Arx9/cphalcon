
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/math.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Helper\Str
 *
 * This class offers quick string functions throughout the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Str) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Str, phalcon, helper_str, phalcon_helper_str_method_entry, 0);

	zephir_declare_class_constant_long(phalcon_helper_str_ce, SL("RANDOM_ALNUM"), 0);

	zephir_declare_class_constant_long(phalcon_helper_str_ce, SL("RANDOM_ALPHA"), 1);

	zephir_declare_class_constant_long(phalcon_helper_str_ce, SL("RANDOM_DISTINCT"), 5);

	zephir_declare_class_constant_long(phalcon_helper_str_ce, SL("RANDOM_HEXDEC"), 2);

	zephir_declare_class_constant_long(phalcon_helper_str_ce, SL("RANDOM_NOZERO"), 4);

	zephir_declare_class_constant_long(phalcon_helper_str_ce, SL("RANDOM_NUMERIC"), 3);

	return SUCCESS;

}

/**
 * Converts strings to camelize style
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::camelize("coco_bongo");            // CocoBongo
 * echo Str::camelize("co_co-bon_go", "-");     // Co_coBon_go
 * echo Str::camelize("co_co-bon_go", "_-");    // CoCoBonGo
 * </code>
 *
 * @param string $text
 * @param mixed  $delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, camelize) {

	zval *text_param = NULL, *delimiter = NULL, delimiter_sub, __$null, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		delimiter = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &text, delimiter );
	RETURN_CCTOR(&_0);

}

/**
 * Concatenates strings using the separator only once without duplication in
 * places concatenation
 *
 * <code>
 * $str = Phalcon\Helper\Str::concat(
 *     "/",
 *     "/tmp/",
 *     "/folder_1/",
 *     "/folder_2",
 *     "folder_3/"
 * );
 *
 * echo $str;   // /tmp/folder_1/folder_2/folder_3/
 * </code>
 *
 * @param string separator
 * @param string a
 * @param string b
 * @param string ...N
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, concat) {

	zval argument, arguments, data, first, last, prefix, delimiter, suffix, _1, _5, *_7, _10, _8$$6, _9$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arguments);
	zephir_get_args(&arguments);
	if (UNEXPECTED(zephir_fast_count_int(&arguments TSRMLS_CC) < 3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_helper_exception_ce, "concat needs at least three parameters", "phalcon/Helper/Str.zep", 81);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&delimiter, phalcon_helper_arr_ce, "first", &_0, 232, &arguments);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_helper_arr_ce, "sliceright", &_2, 233, &arguments);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&arguments, &_1);
	ZEPHIR_CALL_CE_STATIC(&first, phalcon_helper_arr_ce, "first", &_0, 232, &arguments);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&last, phalcon_helper_arr_ce, "last", &_3, 103, &arguments);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefix);
	ZVAL_STRING(&prefix, "");
	ZEPHIR_INIT_VAR(&suffix);
	ZVAL_STRING(&suffix, "");
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_SELF(&_1, "startswith", &_4, 234, &first, &delimiter);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CPY_WRT(&prefix, &delimiter);
	}
	ZEPHIR_CALL_SELF(&_5, "endswith", &_6, 235, &last, &delimiter);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CPY_WRT(&suffix, &delimiter);
	}
	zephir_is_iterable(&arguments, 0, "phalcon/Helper/Str.zep", 105);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _7)
	{
		ZEPHIR_INIT_NVAR(&argument);
		ZVAL_COPY(&argument, _7);
		ZEPHIR_INIT_NVAR(&_8$$6);
		ZEPHIR_INIT_NVAR(&_9$$6);
		zephir_fast_trim(&_9$$6, &argument, &delimiter, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		zephir_fast_trim(&_8$$6, &_9$$6, &delimiter, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		zephir_array_append(&data, &_8$$6, PH_SEPARATE, "phalcon/Helper/Str.zep", 102);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_join(&_10, &delimiter, &data TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, &prefix, &_10, &suffix);
	RETURN_MM();

}

/**
 * Retuns number of vowels in provided string. Uses a regular expression
 * to count the number of vowels (A, E, I, O, U) in a string.
 *
 * @param string $string
 *
 * @return int
 */
PHP_METHOD(Phalcon_Helper_Str, countVowels) {

	zval *text_param = NULL, matches, _0, _1, _2, _3;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/[aeiou]/i");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/[aeiou]/i");
	zephir_preg_match(&_1, &_2, &text, &matches, 1, 0 , 0  TSRMLS_CC);
	zephir_array_fetch_long(&_3, &matches, 0, PH_NOISY | PH_READONLY, "phalcon/Helper/Str.zep", 122 TSRMLS_CC);
	RETURN_MM_LONG(zephir_fast_count_int(&_3 TSRMLS_CC));

}

/**
 * Decapitalizes the first letter of the sring and then adds it with rest
 * of the string. Omit the upperRest parameter to keep the rest of the
 * string intact, or set it to true to convert to uppercase.
 *
 * @param string $string
 * @param bool   $upperRest
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, decapitalize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool upperRest;
	zval *text_param = NULL, *upperRest_param = NULL, *encoding_param = NULL, substr, suffix, _0$$3, _1$$4, _2$$9, _3$$9, _4$$9, _5$$9, _6$$10, _7$$10, _8$$10, _9$$10;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&substr);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &upperRest_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!upperRest_param) {
		upperRest = 0;
	} else {
		upperRest = zephir_get_boolval(upperRest_param);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_substr") TSRMLS_CC) == SUCCESS)) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_CALL_FUNCTION(&substr, "mb_substr", NULL, 147, &text, &_0$$3);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_1$$4, 1);
		ZEPHIR_INIT_NVAR(&substr);
		zephir_substr(&substr, &text, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	if (upperRest) {
		if ((zephir_function_exists_ex(SL("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&suffix, "mb_strtoupper", NULL, 236, &substr, &encoding);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&suffix, &substr, "upper", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&suffix, &substr);
	}
	if ((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZVAL_LONG(&_2$$9, 0);
		ZVAL_LONG(&_3$$9, 1);
		ZEPHIR_CALL_FUNCTION(&_4$$9, "mb_substr", NULL, 147, &text, &_2$$9, &_3$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$9, "mb_strtolower", NULL, 237, &_4$$9, &encoding);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &_5$$9, &suffix);
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(&_6$$10);
		ZVAL_LONG(&_7$$10, 0);
		ZVAL_LONG(&_8$$10, 1);
		ZEPHIR_INIT_VAR(&_9$$10);
		zephir_substr(&_9$$10, &text, 0 , 1 , 0);
		zephir_fast_strtolower(&_6$$10, &_9$$10);
		ZEPHIR_CONCAT_VV(return_value, &_6$$10, &suffix);
		RETURN_MM();
	}

}

/**
 * Accepts a file name (without extension) and returns a calculated
 * directory structure with the filename in the end
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::dirFromFile("file1234.jpg"); // /fi/le/12/file1234.jpg
 * </code>
 *
 * @param string $file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, dirFromFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, name, start, _0, _1, _4, _5, _6, _2$$3, _3$$3;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}


	ZVAL_LONG(&_0, 8);
	ZEPHIR_CALL_FUNCTION(&name, "pathinfo", NULL, 79, &file, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, -2);
	ZEPHIR_INIT_VAR(&start);
	zephir_substr(&start, &name, 0 , -2 , 0);
	if (!(zephir_is_true(&start))) {
		ZVAL_LONG(&_2$$3, 0);
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_INIT_NVAR(&start);
		zephir_substr(&start, &name, 0 , 1 , 0);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_FUNCTION(&_6, "str_split", NULL, 78, &start, &_5);
	zephir_check_call_status();
	zephir_fast_join_str(&_4, SL("/"), &_6 TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, &_4, "/");
	RETURN_MM();

}

/**
 * Accepts a directory name and ensures that it ends with
 * DIRECTORY_SEPARATOR
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::dirSeparator("/home/phalcon"); // /home/phalcon/
 * </code>
 *
 * @param string $directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, dirSeparator) {

	zval *directory_param = NULL, _0, _1;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory_param);

	if (UNEXPECTED(Z_TYPE_P(directory_param) != IS_STRING && Z_TYPE_P(directory_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'directory' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(directory_param) == IS_STRING)) {
		zephir_get_strval(&directory, directory_param);
	} else {
		ZEPHIR_INIT_VAR(&directory);
		ZVAL_EMPTY_STRING(&directory);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &directory, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();

}

/**
 * Generates random text in accordance with the template
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * // Hi my name is a Bob
 * echo Str::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
 *
 * // Hi my name is a Jon
 * echo Str::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
 *
 * // Hello my name is a Bob
 * echo Str::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
 *
 * // Hello my name is a Zyxep
 * echo Str::dynamic(
 *     "[Hi/Hello], my name is a [Zyxep/Mark]!",
 *     "[", "]",
 *     "/"
 * );
 * </code>
 *
 * @param string $text
 * @param string $leftDelimiter
 * @param string $rightDelimiter
 * @param string $separator
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, dynamic) {

	zend_bool _7$$6;
	zephir_fcall_cache_entry *_10 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *leftDelimiter_param = NULL, *rightDelimiter_param = NULL, *separator_param = NULL, ldS, rdS, matches, match, words, word, sub, _0, _1, _4, _5, _2$$3, *_6$$5, _8$$6, _9$$6, _11$$6, _12$$6, _13$$6, _14$$6;
	zval text, leftDelimiter, rightDelimiter, separator, pattern, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&leftDelimiter);
	ZVAL_UNDEF(&rightDelimiter);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&ldS);
	ZVAL_UNDEF(&rdS);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&words);
	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &leftDelimiter_param, &rightDelimiter_param, &separator_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!leftDelimiter_param) {
		ZEPHIR_INIT_VAR(&leftDelimiter);
		ZVAL_STRING(&leftDelimiter, "{");
	} else {
	if (UNEXPECTED(Z_TYPE_P(leftDelimiter_param) != IS_STRING && Z_TYPE_P(leftDelimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'leftDelimiter' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(leftDelimiter_param) == IS_STRING)) {
		zephir_get_strval(&leftDelimiter, leftDelimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&leftDelimiter);
		ZVAL_EMPTY_STRING(&leftDelimiter);
	}
	}
	if (!rightDelimiter_param) {
		ZEPHIR_INIT_VAR(&rightDelimiter);
		ZVAL_STRING(&rightDelimiter, "}");
	} else {
	if (UNEXPECTED(Z_TYPE_P(rightDelimiter_param) != IS_STRING && Z_TYPE_P(rightDelimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rightDelimiter' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(rightDelimiter_param) == IS_STRING)) {
		zephir_get_strval(&rightDelimiter, rightDelimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&rightDelimiter);
		ZVAL_EMPTY_STRING(&rightDelimiter);
	}
	}
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "|");
	} else {
	if (UNEXPECTED(Z_TYPE_P(separator_param) != IS_STRING && Z_TYPE_P(separator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'separator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(separator_param) == IS_STRING)) {
		zephir_get_strval(&separator, separator_param);
	} else {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_EMPTY_STRING(&separator);
	}
	}


	ZEPHIR_CALL_FUNCTION(&_0, "substr_count", NULL, 238, &text, &leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", NULL, 238, &text, &rightDelimiter);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_0, &_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Syntax error in string \"", &text, "\"");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 239, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Helper/Str.zep", 257 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ldS, "preg_quote", NULL, 240, &leftDelimiter);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rdS, "preg_quote", NULL, 240, &rightDelimiter);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVVSVS(&_4, "/", &ldS, "([^", &ldS, &rdS, "]+)", &rdS, "/");
	zephir_get_strval(&pattern, &_4);
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&_5);
	zephir_preg_match(&_5, &pattern, &text, &matches, 1, 2 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_5))) {
		RETURN_CTOR(&text);
	}
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		zephir_is_iterable(&matches, 0, "phalcon/Helper/Str.zep", 280);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _6$$5)
		{
			ZEPHIR_INIT_NVAR(&match);
			ZVAL_COPY(&match, _6$$5);
			_7$$6 = !(zephir_array_isset_long(&match, 0));
			if (!(_7$$6)) {
				_7$$6 = !(zephir_array_isset_long(&match, 1));
			}
			if (_7$$6) {
				continue;
			}
			zephir_array_fetch_long(&_8$$6, &match, 1, PH_NOISY | PH_READONLY, "phalcon/Helper/Str.zep", 275 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&words);
			zephir_fast_explode(&words, &separator, &_8$$6, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&word);
			ZEPHIR_CALL_FUNCTION(&_9$$6, "array_rand", &_10, 241, &words);
			zephir_check_call_status();
			zephir_array_fetch(&word, &words, &_9$$6, PH_NOISY, "phalcon/Helper/Str.zep", 276 TSRMLS_CC);
			zephir_array_fetch_long(&_11$$6, &match, 0, PH_NOISY | PH_READONLY, "phalcon/Helper/Str.zep", 277 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&sub, "preg_quote", NULL, 240, &_11$$6, &separator);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12$$6);
			ZEPHIR_CONCAT_SVS(&_12$$6, "/", &sub, "/");
			ZVAL_LONG(&_13$$6, 1);
			ZEPHIR_CALL_FUNCTION(&_14$$6, "preg_replace", &_15, 25, &_12$$6, &word, &text, &_13$$6);
			zephir_check_call_status();
			zephir_get_strval(&text, &_14$$6);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&match);
	}
	RETURN_CTOR(&text);

}

/**
 * Check if a string ends with a given string
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::endsWith("Hello", "llo");          // true
 * echo Str::endsWith("Hello", "LLO", false);   // false
 * echo Str::endsWith("Hello", "LLO");          // true
 * </code>
 *
 * @param string $text
 * @param string $end
 * @param bool   $ignoreCase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, endsWith) {

	zend_bool ignoreCase;
	zval *text_param = NULL, *end_param = NULL, *ignoreCase_param = NULL, _0;
	zval text, end;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &text_param, &end_param, &ignoreCase_param);

	zephir_get_strval(&text, text_param);
	zephir_get_strval(&end, end_param);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZVAL_BOOL(&_0, (ignoreCase ? 1 : 0));
	RETURN_MM_BOOL(zephir_end_with(&text, &end, &_0));

}

/**
 * Returns the first string there is between the strings from the
 * parameter start and end.
 *
 * @param string $text
 * @param string $start
 * @param string $end
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, firstBetween) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *start_param = NULL, *end_param = NULL, __$true, _0$$3, _1$$3, _3$$4, _4$$4;
	zval text, start, end, _2$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &text_param, &start_param, &end_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (UNEXPECTED(Z_TYPE_P(start_param) != IS_STRING && Z_TYPE_P(start_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'start' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(start_param) == IS_STRING)) {
		zephir_get_strval(&start, start_param);
	} else {
		ZEPHIR_INIT_VAR(&start);
		ZVAL_EMPTY_STRING(&start);
	}
	if (UNEXPECTED(Z_TYPE_P(end_param) != IS_STRING && Z_TYPE_P(end_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'end' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(end_param) == IS_STRING)) {
		zephir_get_strval(&end, end_param);
	} else {
		ZEPHIR_INIT_VAR(&end);
		ZVAL_EMPTY_STRING(&end);
	}


	if ((zephir_function_exists_ex(SL("mb_strstr") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "mb_strstr", NULL, 242, &text, &start);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1$$3, "mb_strstr", NULL, 242, &_0$$3, &end, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &start, &end);
		zephir_fast_trim(return_value, &_1$$3, &_2$$3, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		RETURN_MM();
	} else {
		ZEPHIR_CALL_FUNCTION(&_3$$4, "strstr", NULL, 243, &text, &start);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4$$4, "strstr", NULL, 243, &_3$$4, &end, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VV(&_5$$4, &start, &end);
		zephir_fast_trim(return_value, &_4$$4, &_5$$4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		RETURN_MM();
	}

}

/**
 * Makes an underscored or dashed phrase human-readable
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::humanize("start-a-horse"); // "start a horse"
 * echo Str::humanize("five_cats");     // "five cats"
 * </code>
 *
 * @param string $text
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, humanize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0, _1, _2;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#[_-]+#");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " ");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 25, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Lets you determine whether or not a string includes another string.
 *
 * @param string $needle
 * @param string $haystack
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, includes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *needle_param = NULL, *haystack_param = NULL, _0$$3, _1$$4;
	zval needle, haystack;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&haystack);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &needle_param, &haystack_param);

	if (UNEXPECTED(Z_TYPE_P(needle_param) != IS_STRING && Z_TYPE_P(needle_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'needle' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(needle_param) == IS_STRING)) {
		zephir_get_strval(&needle, needle_param);
	} else {
		ZEPHIR_INIT_VAR(&needle);
		ZVAL_EMPTY_STRING(&needle);
	}
	if (UNEXPECTED(Z_TYPE_P(haystack_param) != IS_STRING && Z_TYPE_P(haystack_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'haystack' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(haystack_param) == IS_STRING)) {
		zephir_get_strval(&haystack, haystack_param);
	} else {
		ZEPHIR_INIT_VAR(&haystack);
		ZVAL_EMPTY_STRING(&haystack);
	}


	if ((zephir_function_exists_ex(SL("mb_strpos") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "mb_strpos", NULL, 244, &haystack, &needle);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(&_0$$3));
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_strpos(&_1$$4, &haystack, &needle, 0 );
		RETURN_MM_BOOL(zephir_get_boolval(&_1$$4));
	}

}

/**
 * Adds a number to a string or increment that number if it already is
 * defined
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::increment("a");    // "a_1"
 * echo Str::increment("a_1");  // "a_2"
 * </code>
 *
 * @param string $text
 * @param string $separator
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, increment) {

	zval *text_param = NULL, *separator_param = NULL, parts, number, _0;
	zval text, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &separator_param);

	zephir_get_strval(&text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode(&parts, &separator, &text, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&number);
	if (zephir_array_isset_long_fetch(&number, &parts, 1, 0 TSRMLS_CC)) {
		ZEPHIR_SEPARATE(&number);
		zephir_increment(&number);
	} else {
		ZEPHIR_INIT_NVAR(&number);
		ZVAL_LONG(&number, 1);
	}
	zephir_array_fetch_long(&_0, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Helper/Str.zep", 394 TSRMLS_CC);
	ZEPHIR_CONCAT_VVV(return_value, &_0, &separator, &number);
	RETURN_MM();

}

/**
 * Compare two strings and returns true if both strings are anagram,
 * false otherwise.
 *
 * @param string $first
 * @param string $second
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, isAnagram) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *first_param = NULL, *second_param = NULL, _0, _1, _2;
	zval first, second;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&second);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);

	if (UNEXPECTED(Z_TYPE_P(first_param) != IS_STRING && Z_TYPE_P(first_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'first' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(first_param) == IS_STRING)) {
		zephir_get_strval(&first, first_param);
	} else {
		ZEPHIR_INIT_VAR(&first);
		ZVAL_EMPTY_STRING(&first);
	}
	if (UNEXPECTED(Z_TYPE_P(second_param) != IS_STRING && Z_TYPE_P(second_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'second' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(second_param) == IS_STRING)) {
		zephir_get_strval(&second, second_param);
	} else {
		ZEPHIR_INIT_VAR(&second);
		ZVAL_EMPTY_STRING(&second);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&_1, "count_chars", NULL, 245, &first, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "count_chars", NULL, 245, &second, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_1, &_2));

}

/**
 * Returns true if the given string is lower case, false otherwise.
 *
 * @param string $text
 * @param string $encoding
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, isLower) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding_param = NULL, _0$$3, _1$$4, _2$$4;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "mb_strtolower", NULL, 237, &text, &encoding);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&text, &_0$$3));
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fast_strtolower(&_2$$4, &text);
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&text, &_2$$4));
	}

}

/**
 * Returns true if the given string is a palindrome, false otherwise.
 *
 * @param string $text
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, isPalindrome) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strrev", NULL, 246, &text);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_0, &text));

}

/**
 * Returns true if the given string is upper case, false otherwise.
 *
 * @param string text
 * @param string encoding
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, isUpper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding_param = NULL, _0$$3, _1$$4, _2$$4;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "mb_strtoupper", NULL, 236, &text, &encoding);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&text, &_0$$3));
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fast_strtoupper(&_2$$4, &text);
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&text, &_2$$4));
	}

}

/**
 * Lowercases a string, this function makes use of the mbstring extension if
 * available
 *
 * <code>
 * echo Phalcon\Helper\Str::lower("HELLO"); // hello
 * </code>
 *
 * @param string $text
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, lower) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding_param = NULL, _0;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 237, &text, &encoding);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &text);
	RETURN_CCTOR(&_0);

}

/**
 * Generates a random string based on the given type. Type is one of the
 * RANDOM_* constants
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::random(Str::RANDOM_ALNUM); // "aloiwkqz"
 * </code>
 *
 * @param int $type
 * @param int $length
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, random) {

	zval text;
	long length;
	zval *type_param = NULL, *length_param = NULL, pool, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$5, _11$$5, _12$$6, _13$$6, _14$$7, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$9, _23$$9, _24$$9;
	zend_long type, ZEPHIR_LAST_CALL_STATUS, end = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pool);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type_param, &length_param);

	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!length_param) {
		length = 8;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZEPHIR_INIT_VAR(&text);
	ZVAL_STRING(&text, "");
	do {
		if (type == 1) {
			ZEPHIR_INIT_VAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "a");
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "z");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "range", NULL, 247, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "A");
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Z");
			ZEPHIR_CALL_FUNCTION(&_3$$3, "range", NULL, 247, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&pool);
			zephir_fast_array_merge(&pool, &_2$$3, &_3$$3 TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZVAL_LONG(&_4$$4, 0);
			ZVAL_LONG(&_5$$4, 9);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "range", NULL, 247, &_4$$4, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "a");
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "f");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "range", NULL, 247, &_7$$4, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&pool);
			zephir_fast_array_merge(&pool, &_6$$4, &_9$$4 TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZVAL_LONG(&_10$$5, 0);
			ZVAL_LONG(&_11$$5, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", NULL, 247, &_10$$5, &_11$$5);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZVAL_LONG(&_12$$6, 1);
			ZVAL_LONG(&_13$$6, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", NULL, 247, &_12$$6, &_13$$6);
			zephir_check_call_status();
			break;
		}
		if (type == 5) {
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "2345679ACDEFHJKLMNPRSTUVWXYZ");
			ZEPHIR_CALL_FUNCTION(&pool, "str_split", NULL, 78, &_14$$7);
			zephir_check_call_status();
			break;
		}
		ZVAL_LONG(&_15$$8, 0);
		ZVAL_LONG(&_16$$8, 9);
		ZEPHIR_CALL_FUNCTION(&_17$$8, "range", NULL, 247, &_15$$8, &_16$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_18$$8);
		ZVAL_STRING(&_18$$8, "a");
		ZEPHIR_INIT_VAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "z");
		ZEPHIR_CALL_FUNCTION(&_20$$8, "range", NULL, 247, &_18$$8, &_19$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_18$$8);
		ZVAL_STRING(&_18$$8, "A");
		ZEPHIR_INIT_NVAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "Z");
		ZEPHIR_CALL_FUNCTION(&_21$$8, "range", NULL, 247, &_18$$8, &_19$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", NULL, 248, &_17$$8, &_20$$8, &_21$$8);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(&pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(&text) < length)) {
			break;
		}
		ZVAL_LONG(&_23$$9, 0);
		ZVAL_LONG(&_24$$9, end);
		zephir_array_fetch_long(&_22$$9, &pool, zephir_mt_rand(zephir_get_intval(&_23$$9), zephir_get_intval(&_24$$9) TSRMLS_CC), PH_NOISY | PH_READONLY, "phalcon/Helper/Str.zep", 540 TSRMLS_CC);
		zephir_concat_self(&text, &_22$$9 TSRMLS_CC);
	}
	RETURN_CTOR(&text);

}

/**
 * Reduces multiple slashes in a string to single slashes
 *
 * <code>
 * // foo/bar/baz
 * echo Phalcon\Helper\Str::reduceSlashes("foo//bar/baz");
 *
 * // http://foo.bar/baz/buz
 * echo Phalcon\Helper\Str::reduceSlashes("http://foo.bar///baz/buz");
 * </code>
 *
 * @param string $text
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, reduceSlashes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#(?<!:)//+#");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 25, &_0, &_1, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a string starts with a given string
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::startsWith("Hello", "He");         // true
 * echo Str::startsWith("Hello", "he", false);  // false
 * echo Str::startsWith("Hello", "he");         // true
 * </code>
 *
 * @param string $text
 * @param string $start
 * @param bool   $ignoreCase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Str, startsWith) {

	zend_bool ignoreCase;
	zval *text_param = NULL, *start_param = NULL, *ignoreCase_param = NULL, _0;
	zval text, start;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &text_param, &start_param, &ignoreCase_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (UNEXPECTED(Z_TYPE_P(start_param) != IS_STRING && Z_TYPE_P(start_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'start' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(start_param) == IS_STRING)) {
		zephir_get_strval(&start, start_param);
	} else {
		ZEPHIR_INIT_VAR(&start);
		ZVAL_EMPTY_STRING(&start);
	}
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		ignoreCase = zephir_get_boolval(ignoreCase_param);
	}


	ZVAL_BOOL(&_0, (ignoreCase ? 1 : 0));
	RETURN_MM_BOOL(zephir_start_with(&text, &start, &_0));

}

/**
 * Uncamelize strings which are camelized
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::uncamelize("CocoBongo");       // coco_bongo
 * echo Str::uncamelize("CocoBongo", "-");  // coco-bongo
 * </code>
 *
 * @param string $text
 * @param mixed  $delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, uncamelize) {

	zval *text_param = NULL, *delimiter = NULL, delimiter_sub, __$null, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		delimiter = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_uncamelize(&_0, &text, delimiter );
	RETURN_CCTOR(&_0);

}

/**
 * Makes a phrase underscored instead of spaced
 *
 * <code>
 * use Phalcon\Helper\Str;
 *
 * echo Str::underscore("look behind");     // "look_behind"
 * echo Str::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
 * </code>
 *
 * @param string $text
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, underscore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0, _1, _2;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#\\s+#");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 25, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Uppercases a string, this function makes use of the mbstring extension if
 * available
 *
 * <code>
 * echo Phalcon\Helper\Str::upper("hello"); // HELLO
 * </code>
 *
 * @param string $text
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Str, upper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding_param = NULL, _0;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(&encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_EMPTY_STRING(&encoding);
	}
	}


	if ((zephir_function_exists_ex(SL("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 236, &text, &encoding);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &text);
	RETURN_CCTOR(&_0);

}

