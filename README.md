# Proplang - tool for propositional logics calculations

## Formal grammar structure:
```java
<program>           ::=   <exp>','<program> | <exp>
<exp>               ::=   'in'<prop>    |
                          'out'<formulae>   |
                          <prop>:=<formulae>
<formulae>          ::=   '('<formulae>'^'<formulae>')'  |
                          '('<formulae>'v'<formulae>')'  |
                          '('<formulae>'=>'<formulae>')' |
                          '('<formulae>'<=>'<formulae>')'|
                          '~'<formulae> | <prop> | '0' | '1' | 'F' | 'T' | 'false' | 'true'
```


## Example of Proplang program
The following program reads the value for good_weather proposition
from the input, sets value of proposition good_mood to true calculates the value for proposition go_outside
as the conjunction of the previous propositions and outputs an inverted result.
```php
in good_weather, good_mood := T,
go_outside := (good_weather ^ good_mood),
out ~go_outside
```
