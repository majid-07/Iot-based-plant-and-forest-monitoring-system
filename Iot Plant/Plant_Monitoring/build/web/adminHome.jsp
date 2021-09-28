<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Plant Monitoring</title>

        <!-- Google Fonts -->
        <link href='http://fonts.googleapis.com/css?family=Titillium+Web:400,200,300,700,600' rel='stylesheet' type='text/css'>
        <link href='http://fonts.googleapis.com/css?family=Roboto+Condensed:400,700,300' rel='stylesheet' type='text/css'>
        <link href='http://fonts.googleapis.com/css?family=Raleway:400,100' rel='stylesheet' type='text/css'>

        <!-- Bootstrap -->
        <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">

        <!-- Font Awesome -->
        <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">

        <!-- Custom CSS -->
        <link rel="stylesheet" href="css/owl.carousel.css">
        <link rel="stylesheet" href="style.css">
        <link rel="stylesheet" href="css/responsive.css">

        <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
        <!--[if lt IE 9]>
          <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
          <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
        <![endif]-->
    </head>
    <body>
          <%
            String msg = "", user = "";
            if (session.getAttribute("msg") != null) {
                msg = session.getAttribute("msg").toString();
            } else {
                msg = "";
            }
            
            session.setAttribute("msg", "");

            if (request.getAttribute("user") != null) {
                user = request.getAttribute("user").toString();
            } else {
                user = "";
            }
        %>

        <div class="site-branding-area">
            <div class="container">
                <div class="row">
                    <div class="col-sm-6">
                        <div class="logo">
                            <h1><a href="AdminHome.jsp"><span>Plant Monitoring Server</span></a></h1>
                        </div>
                    </div>
                </div>
            </div>
        </div> <!-- End site branding area -->

        <div class="mainmenu-area">
            <div class="container">
                <div class="row">
                    <div class="navbar-header">
                        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                            <span class="sr-only">Toggle navigation</span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                    </div> 
                    <div class="navbar-collapse collapse">
                        <ul class="nav navbar-nav">

                          
                    <li><a href="adminHome.jsp" class="selected">Home</a></li>
                 
                    <li><a href="view1.jsp">View Data</a></li>
                    <li><a href="index.jsp">Logout</a></li> 
               
                            
                        </ul>


                    </div>  
                </div>
            </div>
        </div> <!-- End mainmenu area -->

        <div class="slider-area">
            <div class="zigzag-bottom"></div>
            <div id="slide-list" class="carousel carousel-fade slide" data-ride="carousel">

                <div class="slide-bulletz">
                    <div class="container">
                        <div class="row">
                            <div class="col-md-12">
                                <ol class="carousel-indicators slide-indicators">
                                    <li data-target="#slide-list" data-slide-to="0" class="active"></li>
                                    <!--<li data-target="#slide-list" data-slide-to="1"></li>
                                    <li data-target="#slide-list" data-slide-to="2"></li>-->
                                </ol>                            
                            </div>
                        </div>
                    </div>
                </div>

                <!--<div class="carousel-inner" role="listbox">-->
                    <div class="item active">
                        <div class="single-slide">
                            <div class="slide-bg slide-one"></div>
                            <div class="slide-text-wrapper">
                                <div class="slide-text">
                                    <div class="container">
                                        <div class="row">
                                            <div class="col-md-6 col-md-offset-6">
                                                 <h3 style="color: #1abc9c;"> Welcome Admin</h3><br/>  </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                   <!-- <div class="item">
                        <div class="single-slide">
                            <div class="slide-bg slide-two"></div>
                            <div class="slide-text-wrapper">
                                <div class="slide-text">
                                    <div class="container">
                                        <div class="row">
                                             <div class="col-md-6 col-md-offset-6">
                                                 <h3 style="color: #1abc9c;">Smart College Lab</h3><br/>  </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="item">
                        <div class="single-slide">
                            <div class="slide-bg slide-three"></div>
                            <div class="slide-text-wrapper">
                                <div class="slide-text">
                                    <div class="container">
                                        <div class="row">
                                             <div class="col-md-6 col-md-offset-6">
                                                <h3 style="color: #1abc9c;">Smart College Lab</h3><br/> </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>-->
                </div>

            </div>        
        </div> <!-- End slider area -->





        <!-- End product widget area -->

        <!-- End footer top area -->

        <div class="footer-bottom-area">
            <div class="container">
                <div class="row">
                    <div class="col-md-8">
                        <div class="copyright">
                            <p>&copy; 2020 Plant Monitoring. All Rights Reserved.</p>
                        </div>
                    </div>

                   
                </div>
            </div>
        </div> <!-- End footer bottom area -->

        <!-- Latest jQuery form server -->
        <script src="https://code.jquery.com/jquery.min.js"></script>

        <!-- Bootstrap JS form CDN -->
        <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>

        <!-- jQuery sticky menu -->
        <script src="js/owl.carousel.min.js"></script>
        <script src="js/jquery.sticky.js"></script>

        <!-- jQuery easing -->
        <script src="js/jquery.easing.1.3.min.js"></script>

        <!-- Main Script -->
        <script src="js/main.js"></script>
    </body>
</html>