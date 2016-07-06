/* pear */

open Pear_token;
open Test_pear;
open Pear_balance;
open Pear_utils;
open Pear_parse;
open Pear_type;
open Pear_type_old;
/* open Pear_compile; */

let main => {

  /* let state = Stream.of_channel stdin; */

  let state = "
map { b 1 2 }
";

  /*
  Printf.printf "start:\n\t%s\n\n" state;
  */

  let state = Stream.of_string state;

  let state = Pear_token.token state;

  let state = Pear_balance.balance state;

  let state = Pear_parse.parse state;

  let state = Pear_type_old.infer state;

  /*
   * let state = Pear_compile.compile state;

  print_string "tree:\n\t";
  print_string (Pear_type_old.string_of_typed_tree state);
  print_string "\n";
   */
};

switch (main ()) {
  | _ => ();
  | exception e => Pear_utils.print_pear_error e;
}
