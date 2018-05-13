<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div style="height: 470px;text-align:center;">
            <asp:Image ID="Image1" runat="server" Height="140px" Width="340px" BorderWidth="2px" ImageUrl="~/img/one.jpg" />
            <br />
            <br />
            <asp:DropDownList ID="DropDownList1" runat="server" Height="30px" Width="340">
                <asp:ListItem Selected="True"> </asp:ListItem>
                <asp:ListItem>A</asp:ListItem>
                <asp:ListItem>B</asp:ListItem>
                <asp:ListItem Value="C"> C</asp:ListItem>
            </asp:DropDownList>
&nbsp;<br />
            <br />
            <asp:Label ID="Label1" runat="server" ForeColor="Red"></asp:Label>
            <br />
            <br />
            <asp:Label ID="Label2" runat="server"></asp:Label>
            <br />
            <br />
            &nbsp;<asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Next" Width="100px" />
        &nbsp; <asp:Button ID="Button2" runat="server" Text="Update"  Width="100px" OnClick="Button2_Click" />
        &nbsp; <asp:Button ID="Button3" runat="server" Text="Remove" Width="100px" OnClick="Button3_Click"  />
        </div>
    </form>
</body>
</html>
