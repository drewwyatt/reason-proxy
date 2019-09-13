let handler: AwsLambda.APIGatewayProxy.handler =
  (_event, _context, cb) => {
    cb(
      Js.null, /* no error, we want null here */
      /* this function is a helper to return a correctly formated response */
      AwsLambda.APIGatewayProxy.result(
        ~body=`Plain("Hello from reason code!"),
        ~statusCode=200,
        (),
      ),
    );
    Js.Promise.resolve();
  };