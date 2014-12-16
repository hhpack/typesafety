<?hh //strict

namespace typesafety;

use ImmVector;

type Version = string;
type Errors = ImmVector<Error>;
type Messages = Traversable<Message>;
type ImmutableMessages = ImmVector<Message>;
type Path = string;
type LineNumber = int;
type ColumnNumber = int;
