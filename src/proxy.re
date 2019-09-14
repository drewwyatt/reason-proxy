let handler: AwsLambda.APIGatewayProxy.handler =
  (event, _context) => {
    open AwsLambda.APIGatewayProxy;
    let promise =
      Js.Promise.make((~resolve, ~reject as _) => {
        let greeting =
          switch (event->Event.bodyGet->Js.Nullable.toOption) {
          | None => "Hello from reason!"
          | Some(n) => "Hello, " ++ n ++ "!"
          };
        resolve(. result(~body=`Plain(greeting), ~statusCode=200, ()));
      });

    promise;
  };